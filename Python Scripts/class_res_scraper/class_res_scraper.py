import os
import sys 
import requests
import lxml.html
from urllib.parse import urljoin
from urllib.request import urlopen

from bs4 import BeautifulSoup

import json
import re

# for running CS 538
# python3 class_res_scraper.py https://docs.google.com/spreadsheets/d/1NWAoMkR9jbGxotpeeEH4sCuKzWlIjyHqVMz94aWejzM/htmlembed/sheet\?gid\=0

# ASSUMPTION: make sure directory ends with /
directory = "/home/nsleung/Documents/UIUC/Masters_20-21/CS439_FA17/"

# BYPRODUCT: actually writes json file
# RETURN: history list
def generate_history_log(dir_name):
    history = []
    
    # (_, _, filenames) = os.walk(directory).next()
    for _, _, filenames in os.walk(directory+dir_name):
        # for name in files:
        #     print(os.path.join(directory, name))
        history.extend(filenames)
        break
    
    print ("history", history)
    logfilename = directory + dir_name + '/' + dir_name + 'log.json'
    f = open(logfilename, 'w')
    json.dump(history, f, indent=2)
    # with open(logfilename, 'w') as f:
    #     # indent=2 is not needed but makes the file more 
    #     # human-readable for more complicated data
    #     json.dump(history, f, indent=2) 

    return history

# RETURN: reduced dict structure
def reduce_dl(gen_struct):

    reduced_gen_struct = {}
    for dir_name, _ in gen_struct.items():
        # dir_name should match exact name if exists

        #try to retrieve history (stored as json dump)
        logfilename = directory + dir_name + '/' + dir_name + 'log.json'
        history = []
        try:
            f = open(logfilename, 'r')
            history = json.load(f)
        except FileNotFoundError:
            print(dir_name+'log.json not found...must be first time running script')
        # with open(logfilename, 'r') as f:
        #     history = json.load(f)
        
        #get list inside gen_dict
        gen_list = gen_struct[dir_name]
        comp_list = []
        #clean up gen_list
        for name in gen_list:
            comp_list.append(name.split('/')[-1])

        #compute difference
        history_set = set(history)
        print("history_set: ", history_set)
        gen_list_set = set(comp_list)
        print("gen_list_set: ", gen_list_set)
        to_add_set = gen_list_set - history_set
        print("to_add_set: ", to_add_set)
        to_add_list = list(to_add_set)

        #log stuff just to see what's going on
        print(logfilename," has ", len(history), " files")
        print("we are trying to add total ", len(comp_list), " files")
        print("we've reduced it to ", len(to_add_list), " files")

        #populate reduced struct
        try:
            reduced_gen_struct[dir_name] = to_add_list
        except KeyError:
            reduced_gen_struct[dir_name] = []
            reduced_gen_struct[dir_name] = to_add_list
    return reduced_gen_struct

#does smart scraping - only downloads unique files not already downloaded
def scrape_dl(website):
    response = requests.get(website)
    soup = BeautifulSoup(response.text, "html.parser")   
    print(soup)
    # filename = directory  + "log.txt"
    # f = open(filename, 'w+')
    # history = set(generate_history_log())
    total = []
    total_links = []

    gen_struct = {}
    for link in soup.select("a[href$='.pdf']"):
    # for link in soup.select("a[href*='.pdf']"):
        # print("hello,world")
        # print(link['href'])
        # print("processing...")
        # result = re.search('url\\?q=https://courses.(.*).pdf', link['href'])
        # try:
            # print(result.group(1))
            # link['href'] = "https://courses." + result.group(1)
        
        # total.append(link['href'].split('/')[-1])
        total_links.append(link['href'].split('/')[-2])
        # total_links.append("lectures")

        #assume the link can be split in this manner
        try:
            subdir = link['href'].split('/')[-2]
            # subdir = "lectures"

        except IndexError as error:
            print("The full link can't be split to a subdir")
            print("here is the link", link['href'])
            raise
        # try: 
        #     filename = link['href'].split('/')[-1]
        # except IndexError as error:
        #     print("The full link can't be split to a filename")
        #     print("here is the link", link['href'])
        #     raise
        file_link = link['href']
        try:
            gen_struct[subdir].append(file_link)
        except KeyError as error:
            gen_struct[subdir] = []
            gen_struct[subdir].append(file_link)

        # except:
        #     pass

    reduced_gen_struct = reduce_dl(gen_struct)
    print("reduced gen struct: ",reduced_gen_struct)
    # TODO:remove when all good
    # website = "https://courses.engr.illinois.edu/cs538/sp2019/index.html"
    for dir_name, file_link in reduced_gen_struct.items():
        # dir_name = "lectures"
        full_dir = directory + dir_name
        try:
            os.makedirs(directory + dir_name)
            for file_name in file_link:
                #directory already exists
                #Name the pdf files using the last portion of each link which are unique in this case
                filename = os.path.join(full_dir,file_name.split('/')[-1])
                print("writing filename ", file_name.split('/')[-1])
                with open(filename, 'wb') as f:
                    # print("getting " + os.path.dirname(websxite) + '/' +dir_name + '/'+ file_name)
                    # print("dir_name: " +dir_name)
                    # dir_pls = urljoin(os.path.dirname(website),dir_name)
                    # print("dir_pls: " + dir_pls)

                    # TODO: put back when done
                    final = os.path.dirname(website) + '/' + dir_name + '/' + file_name
                    print("getting " + os.path.dirname(website) + '/' + dir_name + '/' + file_name)

                    # final = os.path.dirname(website) + '/' + file_name
                    # print("getting " + os.path.dirname(website) + '/' + file_name)
                    f.write(requests.get(final).content)
        except FileExistsError:
            if len(file_link) > 0:
                for file_name in file_link:
                    #directory already exists
                    #Name the pdf files using the last portion of each link which are unique in this case
                    filename = os.path.join(full_dir,file_name.split('/')[-1])
                    print("writing filename ", file_name.split('/')[-1])
                    with open(filename, 'wb') as f:
                        f.write(requests.get(urljoin(website,file_name)).content)
        
        #finally, generate log files for each directory
        generate_history_log(dir_name)

    # print(gen_struct)
    # total_set = set(total)

    # for dl_item in total_links:
    #     total.append(link.split('/')[-1])

    # to_add = total_set - history #only add unique files that don't exist already

    # for dl_item in total_links:
    #     if (total == dl_item.split('/')[-1]):
    #         filename = os.path.join(directory, dl_item)
    #         with open(filename, "w+") as f:
    #             f.write(requests.get(urljoin(website, dl_item)).content)

# usage: python3 class_res_scraper.py [website]
if __name__ == '__main__':
    website = ""
    if len(sys.argv) > 1:
        website = str(sys.argv[1])
    else:
        print('usage: python3 class_res_scraper.py [website (ex: https://moodle.com)]')

    check = input("Have you made sure the absolute filepath is hard-coded? (Y/N)")
    if check == 'Y' or check == 'y':
        scrape_dl(website)
    
    # generate_history()





    # r = requests.get(website)
    # cwd = os.getcwd()
    # test_file = open(cwd+'/test_files/test_file.html', 'w+')
    # print(r.text, file=test_file)
    

    '''
    # fetch page
    res = urlopen(website)
    # parse response into xml tree
    tree = lxml.html.fromstring(res.read())

    #construct namespace dictionary 
    ns = {'re': 'http://exslt.org/regular-expressions'}

    for node in tree.xpath('//a[re:test(@href, "\.pdf$", "i")]', namespace=ns):
        #print href, joining it to base url
        print (urljoin(website, node.attrib['href']))
    '''

    

    # setup(website)
