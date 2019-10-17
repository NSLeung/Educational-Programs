#!/usr/bin/env python3
import os
# print( os.getcwd())
cwd = os.getcwd()

def find_file(filename, search_path):
    for dirpath, dirnames, filenames in os.walk(search_path):
        if filename in filenames:
            return 1
    return 0

print(find_file("foo_subdir1.txt", cwd))