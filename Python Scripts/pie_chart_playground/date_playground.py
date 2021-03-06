#!/usr/bin/env python

import datetime
import os
#%%
'''
def main():
    today = datetime.datetime.now()
    beginning,end = week_magic(today)
    print("beginning of the week: {} \n end of the week: {}".format(beginning,end))
    print("beginning of the week (Monday): {} \n end of the week (Sunday): {}".format(beginning.strftime("%x"),end))
'''

def week_magic(day):
    day_of_week = day.weekday()

    to_beginning_of_week = datetime.timedelta(days=day_of_week)
    beginning_of_week = day - to_beginning_of_week

    to_end_of_week = datetime.timedelta(days=6 - day_of_week)
    end_of_week = day + to_end_of_week

    return (beginning_of_week, end_of_week)

#%%
def main():
    fp = open_files()
    close_files(fp)
def close_files(fp):
    print("closing fp: {}".format(fp))
    fp.close()
def open_files():
    cwd = os.getcwd()
    filename = "test_open"
    file_p = open(cwd + '/' + filename + '.txt', 'w+')
    return file_p
if __name__ == "__main__":
    main()
