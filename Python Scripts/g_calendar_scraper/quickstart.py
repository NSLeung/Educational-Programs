#!/usr/bin/env python

from __future__ import print_function
import datetime
import rfc3339
import iso8601
import pickle
import os.path
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request

import re

# If modifying these scopes, delete the file token.pickle.
SCOPES = ['https://www.googleapis.com/auth/calendar.readonly']

def main(fp):
    """Shows basic usage of the Google Calendar API.
    Prints the start and name of the next 10 events on the user's calendar.
    """
    creds = None
    # The file token.pickle stores the user's access and refresh tokens, and is
    # created automatically when the authorization flow completes for the first
    # time.
    if os.path.exists('token.pickle'):
        with open('token.pickle', 'rb') as token:
            creds = pickle.load(token)
    # If there are no (valid) credentials available, let the user log in.
    if not creds or not creds.valid:
        if creds and creds.expired and creds.refresh_token:
            creds.refresh(Request())
        else:
            flow = InstalledAppFlow.from_client_secrets_file(
                'credentials.json', SCOPES)
            creds = flow.run_local_server(port=0)
        # Save the credentials for the next run
        with open('token.pickle', 'wb') as token:
            pickle.dump(creds, token)

    service = build('calendar', 'v3', credentials=creds)

    # Call the Calendar API

    
    # today = datetime.datetime.now()
    # d = datetime.timedelta(days=7)  # want to grab on a weekly basis
    # a = today - d
    # start = a.isoformat() + 'Z'

    start, _ = week_magic()
    start = start.isoformat() + 'Z'
    # current = datetime.datetime.now().isoformat()

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time
    # print('Getting the upcoming 10 events')
    print('Getting past events from the beginning of the week')
    events_result = service.events().list(calendarId='primary', timeMin=start, timeMax=now,
                                        maxResults=50, singleEvents=True,
                                        orderBy='startTime').execute()
    events = events_result.get('items', [])
    events_dict = {}

    if not events:
        print('No upcoming events found.')
    for event in events:
        start = event['start'].get('dateTime', event['start'].get('date'))
        end = event['end'].get('dateTime', event['end'].get('date'))

        # compute length of each event
        difference = convert_hr_float(get_date_object(end) - get_date_object(start))
        print("length of event {}: {}".format(event['summary'], difference), file=fp)

        # start filtering events by category

        # use regex
        p = re.compile("\[\w*\]")
        result = p.search(event['summary'])
        
        if result:
            category = result.group(0)
            try:
                events_dict[category] = events_dict[category] + difference
            except KeyError:
                events_dict[category] = 0
                events_dict[category] = events_dict[category] + difference

        else:
            try:
                events_dict["Misc"] = events_dict["Misc"] + difference
            except KeyError:
                events_dict["Misc"] = 0
                events_dict["Misc"] = events_dict["Misc"] + difference

    print(events_dict)
        

def convert_hr_float(date_object):
    # print(float(date_object.total_seconds())/ (60 * 60))
    return float(date_object.total_seconds() / (60 * 60))
def get_date_object(date_string):
  return iso8601.parse_date(date_string)

def get_date_string(date_object):
  return rfc3339.rfc3339(date_object)

def open_file():
    cwd = os.getcwd()
    filename = "events"
    beginning, _ = week_magic()


    file_p = open(cwd + '/' + filename + '_weekof_' + beginning.strftime("%x").replace('/', '-') + '.txt', 'w+')
    # file_p = open(cwd + '/' + 'test.txt', 'w+')
    return file_p
def close_file(fp):
    fp.close()

def week_magic():
    day = datetime.datetime.now()
    day_of_week = day.weekday()

    to_beginning_of_week = datetime.timedelta(days=day_of_week)
    beginning_of_week = day - to_beginning_of_week

    to_end_of_week = datetime.timedelta(days=6 - day_of_week)
    end_of_week = day + to_end_of_week

    return (beginning_of_week, end_of_week)

if __name__ == '__main__':
    fp = open_file()
    main(fp)
    close_file(fp)

'''
NOTES:
- have several views
1) productivity only, no white-space
2) scope of entire day with white-space

'''