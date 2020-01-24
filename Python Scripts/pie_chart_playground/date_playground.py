#!/usr/bin/env python

import datetime

def main():
    today = datetime.datetime.now()
    beginning,end = week_magic(today)
    print("beginning of the week: {} \n end of the week: {}".format(beginning,end))

def week_magic(day):
    day_of_week = day.weekday()

    to_beginning_of_week = datetime.timedelta(days=day_of_week)
    beginning_of_week = day - to_beginning_of_week

    to_end_of_week = datetime.timedelta(days=6 - day_of_week)
    end_of_week = day + to_end_of_week

    return (beginning_of_week, end_of_week)

if __name__ == "__main__":
    main()