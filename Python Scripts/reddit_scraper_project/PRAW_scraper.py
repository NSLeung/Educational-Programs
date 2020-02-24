#%%
#!/usr/bin/python3.6
'''
TODO: make smarter algorithm to determine what things to save instead
of generating and re-writing every single file each time
like a patch macro to redo, or do smart update
'''
import praw
import sys
import csv 
from praw.models import Submission
from prawcore import NotFound, PrawcoreException, Forbidden
import pprint
import os
import sys
import json
from collections import OrderedDict
import time
from time import gmtime, strftime

### Reddit API Credentials
c_id = "x6gF21WvdUDLNA"               # Personal Use Script (14 char)
c_secret = "AgXJdqUWh6Ws_6EgAnpS_6B_5D8"           # Secret key (27 char)
u_a = "Saved_Scraper"               # App name
usrnm = "nsl3109"      # Reddit username
passwd = "Applebob1!"     # Reddit login password

def main():
    ### Reddit Login
    reddit = praw.Reddit(client_id = c_id, \
                         client_secret = c_secret, \
                         user_agent = u_a, \
                         username = usrnm, \
                         password = passwd)
    saved = reddit.user.me().saved(limit=None)

    #variables: count, lists
    """
    MAIN DATA STRUCTURE(S):
    dict = {
        links_dict:
            {
                # keys are Subreddit, values are multi-dimensional lists [0] title [1] url
                Jazz : ["jazz_link_1", "jazz_link_2"], <- link_arr
                AskReddit : ["askreddit_link_1", "askreddit_link_2"] 

            },
        comments_dict:
            {
                # keys are Subreddit, values are multi-dimensional lists [0] title [1] body
                Jazz : ["jazz_comment_1", "jazz_comment_2","jazz_comment_3],
                AskReddit : ["askreddit_comment_1", "askreddit_comment_2"]
            }
        
    }
    """

    saved_item_cnt = 0
    saved_dict = OrderedDict()
    saved_dict["links_dict"] = OrderedDict()
    saved_dict["comments_dict"] = OrderedDict()
    # it_arr = []

    try:
        for item in saved:
            saved_item_cnt = saved_item_cnt + 1 # increment ctr

            if isinstance(item, Submission):
                # It's a link, do link stuff
                try:
                    dict_sub_list = saved_dict["links_dict"][item.subreddit.display_name]
                    dict_title_list = dict_sub_list[0]
                    dict_url_list = dict_sub_list[1]
                    dict_permalink_list = dict_sub_list[2]
                except KeyError as error:
                    # print("first time!")
                    saved_dict["links_dict"][item.subreddit.display_name] = [None] * 3
                    dict_sub_list = saved_dict["links_dict"][item.subreddit.display_name]
                    dict_sub_list[0] = []
                    dict_sub_list[1] = []
                    dict_sub_list[2] = []
                    dict_title_list = dict_sub_list[0]
                    dict_url_list = dict_sub_list[1]
                    dict_permalink_list = dict_sub_list[2]
                dict_title_list.append(item.title)
                dict_url_list.append(item.url)
                dict_permalink_list.append(item.permalink)
                # print(item.title)
                # print(item.url)
                # print(item.subreddit.display_name)
                #pass
            else:
                # It's a comment, do comment stuff
                # print(item.body)
                try:
                    dict_sub_list = saved_dict["comments_dict"][item.subreddit.display_name]
                    dict_title_list = dict_sub_list[0]
                    dict_body_list = dict_sub_list[1]
                    dict_permalink_list = dict_sub_list[2]
                except KeyError as error:
                    saved_dict["comments_dict"][item.subreddit.display_name] = [None] * 3
                    dict_sub_list = saved_dict["comments_dict"][item.subreddit.display_name]
                    dict_sub_list[0] = []
                    dict_sub_list[1] = []
                    dict_sub_list[2] = []
                    dict_title_list = dict_sub_list[0]
                    dict_body_list = dict_sub_list[1]
                    dict_permalink_list = dict_sub_list[2]
                dict_title_list.append(item.submission.title)
                dict_body_list.append(item.body)
                dict_permalink_list.append(item.permalink)
                # pass
    except Forbidden as error:
        print("\nERROR: %s" % error)
        print("Please recheck Reddit credentials.")
    return saved_dict

# saves dictionary state to file
def save_dict(dict_to_save):
    cwd = os.getcwd()
    filename = "dict_json.json"
    json_file = open(cwd + '/' + filename, 'w+')
    json.dump(dict_to_save, json_file)

# print function that has forknowledge of saved_dict's internal structure
def dict_print(dict_to_print):

    # main printing logic
    #1. Links

    links_dict = dict_to_print["links_dict"]
    comments_dict = dict_to_print["comments_dict"]
    loop_print(links_dict, "links")
    loop_print(comments_dict, "comments")


def loop_print(sub_dict, print_type):
    for subReddit, content_arr in sub_dict.items():
        # every subreddit should get its own page
        cwd = os.getcwd()
        filename = subReddit + '_' + print_type + '.md'

        if not os.path.exists('saved_' + print_type):
            os.makedirs('saved_' + print_type)
        file_p = open(cwd + '/saved_' + print_type + '/' + filename, 'w+')
        
        if print_type == "links":
            links_filename_list.append(filename)
        else:
            comments_filename_list.append(filename)

        print("# [" + '/r/' + subReddit + '](https://reddit.com/r/' + subReddit + ')', file=file_p) # subreddit gets primary header in markdown
        for i in range(len(content_arr[0])):
            print('## ' + '[' + content_arr[0][i] + '](' + "https://reddit.com" + content_arr[2][i] + ')', file=file_p) # title gets secondary header
            print(content_arr[1][i], file=file_p)

        file_p.close()  # always close files after opening

def main_print(dict_to_print):
    print("SAVED REDDIT ITEMS FOR /u/nsl3109\n",file=main_file)
    print("last generated on " + strftime("%Y-%m-%d %H:%M:%S", gmtime()),file=main_file)
   
    print("# " + "LINKS",file=main_file)
    linked_subs_len = len(dict_to_print["links_dict"].keys())
    print("Number of SubReddits (saved links): " + str(linked_subs_len),file=main_file)

    idx = 0
    for subReddit,_ in dict_to_print["links_dict"].items():   
        print("* " + '[/saved/r/' + subReddit + ']' + '(./saved_links/' + links_filename_list[idx] + ')',file=main_file)
        idx = idx + 1
    
    print("# " + "COMMENTS ",file=main_file)
    comments_subs_len = len(dict_to_print["comments_dict"].keys())
    print("Number of SubReddits (saved comments): " + str(comments_subs_len),file=main_file)
    idx = 0
    for subReddit,_ in dict_to_print["comments_dict"].items():
        print("* " + '[/saved/r/' + subReddit + ']' + '(./saved_comments/' + comments_filename_list[idx] + ')',file=main_file)
        idx = idx + 1


## MAIN
start_time = time.time() # start timer
print("starting time now..." + str(start_time))

#variables
links_filename_list = []
comments_filename_list = []

main_dict = main()

# print stuff
cwd = os.getcwd()
main_filename = "saved_reddit_main.md"
main_file = open(cwd + '/' + main_filename, 'w+')


# save_dict(main_dict)
dict_print(main_dict)

main_print(main_dict)   # have to call main_print after dict_print to populate filename lists


main_file.close() # close after writing

stop_time = time.time()


# log running stats for future analysis
stats_filename = "runtime_stats.md"
stats_file = open(cwd + '/' + stats_filename, 'w+')
print("--- %s seconds elapsed ---" % (stop_time - start_time))
print("%s seconds elapsed " % (stop_time - start_time), file=stats_file)
print("\n | last generated on " + strftime("%Y-%m-%d %H:%M:%S", gmtime()) + '\n',file=stats_file)

stats_file.close()


#%%
#other stuff
'''

"""
cwd = os.getcwd()
filename = "logFile.txt"
logFile = open(cwd + '/' + filename, 'w+')
sr_list = ["Jazz", "AskReddit"]
val_arr_2 = ["blah", "blah2", "blah3"]
dict = {
    "Subreddit": sr_list,
    "val2" : val_arr_2
}
"""
cwd = os.getcwd()
filename = "logFile.txt"
logFile = open(cwd + '/' + filename, 'w+')
pp = pprint.PrettyPrinter(indent=4,stream=logFile,width=1)
pp.pprint(dict_print)


#%%
"""
    MAIN DATA STRUCTURE(S):
    dict = {
        links_dict:
            {
                # keys are Subreddit, values are lists of respective Subreddits with links
                Jazz : ["jazz_link_1", "jazz_link_2"], <- link_arr
                AskReddit : ["askreddit_link_1", "askreddit_link_2"] 

            },
        comments_dict:
            {
                # keys are Subreddit, values are lists of respective Subreddits with comments
                Jazz : ["jazz_comment_1", "jazz_comment_2","jazz_comment_3],
                AskReddit : ["askreddit_comment_1", "askreddit_comment_2"]
            }
        
    }
"""
class Item:
    def __init__(self, type_lc, subreddit, title, body):
        self.type_lc = type_lc
        self.subreddit = subreddit
        self.title = title
        self.body = body

it1 = Item("link","Jazz", "Title 1", "lorem ipsum do")
it2 = Item("comment","Askreddit", "Interesting question 2", "loreeee")

# initializing stuff
test_dict, links_dict, comments_dict = {}, {}, {}
test_dict["links_dict"] = {}
test_dict["comments_dict"] = {}
it_arr = []
#main action
it_arr.append(it1)
it_arr.append(it2)
for i in range(0, len(it_arr)):
    if it_arr[i].type_lc == "link":
        # try for KeyError to see if key exists
        try:
            # check if list already exists
            dict_sub_list = test_dict["links_dict"][it_arr[i].subreddit]
        except KeyError:
            test_dict["links_dict"][it_arr[i].subreddit] = []
            dict_sub_list = test_dict["links_dict"][it_arr[i].subreddit]
            # dict_sub_list = []
        dict_sub_list.append(it_arr[i].body)

    elif it_arr[i].type_lc == "comment":
        # try for KeyError to see if key exists
        try:
            # check if list already exists
            dict_sub_list = test_dict["comments_dict"][it_arr[i].subreddit]
        except KeyError:
            test_dict["comments_dict"][it_arr[i].subreddit] = []
            dict_sub_list = test_dict["comments_dict"][it_arr[i].subreddit]

        dict_sub_list.append(it_arr[i].body)
    else:
        print("else")
# logging stuff
# print(it1.subreddit)

# end statement
# print("reached end2")
import pprint
pp = pprint.PrettyPrinter(indent=4)
pp.pprint(test_dict)


#%% list appending test

list1 = [1]
ref_list1 = list1
ref_list1.append(2)
print(list1)
#%% garbo test
test_dict = {}
print(type(test_dict["blah"]))

#%% misc dict stuff
default = 'Scruffy'
dog_owned_by = {'Peter': 'Furry', 'Sally': 'Fluffy'}

dogs = []
for owner in ('Peter', 'Sally', 'Tim'):
    dogs.append(dog_owned_by.setdefault(owner, default))

# dogs == ['Furry', 'Fluffy', 'Scruffy']
# dog_owned_by == {'Tim': 'Scruffy', 'Peter': 'Furry', 'Sally': 'Fluffy'}

#%% multi-dimensional lists
list1 = [None] * 2
list1_sub1 = ["title 1", "title2"]
list1_sub2 = ["body 1", "body2"]
list1[0] = list1_sub1
list1[1] = list1_sub2

import pprint
pp = pprint.PrettyPrinter(indent=4)
pp.pprint(list1)



#%% reviewing how functions work in python

# fn that populates a dict and returns it
def foo():
    dict_print = {
        "links" : "print this",
        "comments" : "print this comment"
    }
    return dict_print



def dict_print_fn(dict_to_print):
    import pprint
    pp = pprint.PrettyPrinter(indent=4)
    pp.pprint(dict_to_print["links"])
abc = foo()
dict_print_fn(abc)

#%% trying out OrderedDict
from collections import OrderedDict
import pprint
foo_dict = OrderedDict()
foo_dict["foo"] = "bar"
foo_dict["foo2"] = "bar2"
foo_dict["foo3"] = "bar3"

for foos, bars in foo_dict.items():
    print(foos, bars)
'''