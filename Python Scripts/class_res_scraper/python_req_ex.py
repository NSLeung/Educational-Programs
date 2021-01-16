import requests
import os

# from gw_utility.logging import Logging
# x = requests.get('https://google.com')
# cwd = os.getcwd()
# test_file = open(cwd+'/test_files/test_file.html', 'w+')
# print(x.text, file=test_file)
var = "hi"

def foo():
    print (var)

if __name__ == "__main__":
    # foo()

    a = [1, 2]
    try:
        bob = a[3]
    except IndexError as error:
        print("a can't be accessed that way")
        raise
    a.append(3)
    print(a)