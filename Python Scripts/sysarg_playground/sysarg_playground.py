#!/usr/bin/python3

import sys

print ('Number of arguments: ' + str( len(sys.argv) ) + ' arguments.')
print ('Argument List: '+ str(sys.argv))
if len(sys.argv) > 1:
    print(str(sys.argv[1]))