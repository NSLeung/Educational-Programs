import os
website = "https://courses.engr.illinois.edu/cs438/sp2020/schedule.html"
# print(website.split('/'))

# head, _ = os.path.split(website)
# print(head)

print (os.path.dirname(website))