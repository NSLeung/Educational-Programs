import datetime
import sys
import os
import json

# for scraping
import requests
from bs4 import BeautifulSoup
# seems like I need Selenium to load the DOM before BS can scrape it
from selenium import webdriver
from selenium.webdriver.common.desired_capabilities import DesiredCapabilities
import time

d = datetime.datetime.today()

date = d.strftime('%m-%d-%Y')

#global variables
URL = "https://leetcode.com/problemset/all/"

def scrape_website():
    options = webdriver.ChromeOptions()
    options.add_argument('headless')
    capa = DesiredCapabilities.CHROME
    capa["pageLoadStrategy"] = "none"
    driver = webdriver.Chrome(chrome_options=options, desired_capabilities=capa)
    driver.set_window_size(1440,900)
    driver.get(URL)
    time.sleep(3)

    #page = requests.get(URL)    
    #soup = BeautifulSoup(page.content, 'html.parser')
    page = driver.page_source
    soup = BeautifulSoup(page, 'html.parser')
    # find elements by HTML tag 'td' for table element
    table_rows = soup("tr")
    #print(table_rows)

    struct = dict()

    for elem in table_rows:
        # start parsing out the tr's
        if len(elem.contents) >= 3:
            divs = elem.find('div')
            if divs is not None:
                sauce = elem.contents[2]
                extrasauce = elem.contents[2]['value']
                p_id = elem.contents[1].find(text=True)
                #print(p_id)
                struct[p_id] = extrasauce
    #print(struct)

    # save to file using json dumps
    with open("leetcode_problems", "w") as json_file:
        json.dump(struct, json_file)

    return struct
#scrape_website()


if __name__ == "__main__":
    numArgs = len(sys.argv)
    if numArgs != 3:
        print("please supply [problem ID of challenge] [language] in that exact order")
        exit()
    
    # read back JSON file because we don't want to keep scraping it every time
    f = open("leetcode_problems", )
    struct = json.load(f)


    # assumption: python is the only outlier that gets trimmed (cpp, c is fine cuz I really only use those languages)
    extension = sys.argv[2]
    
    # set up folder
    path = str(sys.argv[1]) + " - " + struct[sys.argv[1]]
    if not os.path.exists(path):
        os.makedirs(path)
    # if python, should just be able to run python3 (hopefully without permission)
    if extension == "python":
        print("huh")
        extension = "py"
    
    filename = path + "." + extension
    with open(os.path.join(path, filename), "w+") as temp_file:
        pass
 

        
