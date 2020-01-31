#!/usr/bin/env python3

from __future__ import print_function
import datetime
import rfc3339
import iso8601
import pickle
import os.path
import sys
from googleapiclient.discovery import build
from google_auth_oauthlib.flow import InstalledAppFlow
from google.auth.transport.requests import Request

import re

import plotly.graph_objects as go

# If modifying these scopes, delete the file token.pickle.
SCOPES = ['https://www.googleapis.com/auth/calendar.readonly']

def main(fp, exec_mode):
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

    
    if(exec_mode == '7-day'):
        today = datetime.datetime.now()
        d = datetime.timedelta(days=7)  # want to grab on a weekly basis
        a = today - d
        start = a.isoformat() + 'Z'
    else: 
        start, _ = week_magic()
        start = start.isoformat() + 'Z'
        current = datetime.datetime.now().isoformat()

    now = datetime.datetime.utcnow().isoformat() + 'Z' # 'Z' indicates UTC time
    # print('Getting the upcoming 10 events')
    print('Getting past events from the beginning of the week')
    events_result = service.events().list(calendarId='primary', timeMin=start, timeMax=now,
                                        maxResults=50, singleEvents=True,
                                        orderBy='startTime').execute()
    events = events_result.get('items', [])
    events_dict = {}
    cumulative_hours = 0

    if not events:
        print('No upcoming events found.')
    for event in events:
        start = event['start'].get('dateTime', event['start'].get('date'))
        end = event['end'].get('dateTime', event['end'].get('date'))

        # compute length of each event
        difference = convert_hr_float(get_date_object(end) - get_date_object(start))
        print("length of event {}: {}".format(event['summary'], difference), file=fp)

        cumulative_hours = cumulative_hours + difference

        # start filtering events by category

        # use regex
        p = re.compile("\[.*?\]")
        result = p.findall(event['summary'])
        
        try:
            category = result[0]
            try:
                hi = result[1]
                try:
                    events_dict[result[1] + ' ' + category] = events_dict[result[1] + ' ' + category] + difference
                except KeyError:
                    events_dict[result[1] + ' ' + category] = 0
                    events_dict[result[1] + ' ' + category] = events_dict[result[1] + ' ' + category] + difference
            except:
                try:
                    events_dict[category] = events_dict[category] + difference
                except KeyError:
                    events_dict[category] = 0
                    events_dict[category] = events_dict[category] + difference

        except:
            try:
                events_dict["Misc"] = events_dict["Misc"] + difference
            except KeyError:
                events_dict["Misc"] = 0
                events_dict["Misc"] = events_dict["Misc"] + difference

    # retrieve the sleep calendar
    # jkikqeh1d8ducarnbmbn92iflc@group.calendar.google.com

    print('Getting sleep data')

    # have to recalculate time
    if(exec_mode == '7-day'):
        today = datetime.datetime.now()
        d = datetime.timedelta(days=7)  # want to grab on a weekly basis
        a = today - d
        start = a.isoformat() + 'Z'
    else: 
        #TODO: calculate time elapsed since beginning of week till now, right now I only calculate 7 days
        start, _ = week_magic()
        start = start.isoformat() + 'Z'
        current = datetime.datetime.now().isoformat()

    events_result = service.events().list(calendarId='jkikqeh1d8ducarnbmbn92iflc@group.calendar.google.com', timeMin=start, timeMax=now,
                                        maxResults=50, singleEvents=True,
                                        orderBy='startTime').execute()
    events = events_result.get('items', [])
    # events_dict = {}

    if not events:
        print('No upcoming events found.')
    for event in events:
        start = event['start'].get('dateTime', event['start'].get('date'))
        end = event['end'].get('dateTime', event['end'].get('date'))

        # compute length of each event
        difference = convert_hr_float(get_date_object(end) - get_date_object(start))
        print("length of sleep period {}: {}".format(event['summary'], difference), file=fp)
        cumulative_hours = cumulative_hours + difference

        # if event['summary'] is 'Sleep':
        try:
            events_dict["Sleep"] = events_dict["Sleep"] + difference
        except KeyError:
            events_dict["Sleep"] = 0
            events_dict["Sleep"] = events_dict["Sleep"] + difference

    # calculation to account for white space (put in misc)
    # if exec_mode == '7-day':
    white_space = (7 * 24) - cumulative_hours
    try:
        events_dict["Misc"] = events_dict["Misc"] + white_space
    except KeyError:
        events_dict["Misc"] = 0
        events_dict["Misc"] = events_dict["Misc"] + white_space

    print(events_dict)

    display_chart(events_dict)

def display_chart(events_dict):
    event_name_list = []
    event_length_list = []
    for event_name, event_length in events_dict.items():
        event_name_list.append(event_name)
        event_length_list.append(event_length)

    fig = go.Figure(data=[go.Pie(labels=event_name_list, values = event_length_list, hole=.4)])
    fig.update_layout(font=dict(
        family="Courier New, monospace",
        size=24
    ))
    fig.show()
        

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
    num_args = len(sys.argv)
    exec_mode = 'default'
    if num_args > 1:
        if sys.argv[1] == '7-day':
            exec_mode = '7-day'
    fp = open_file()
    main(fp, exec_mode)
    close_file(fp)

'''
NOTES:
- have several views
1) productivity only, no white-space
2) scope of entire day with white-space
3) combine sections for productivity (ex: classes, homework)

'''