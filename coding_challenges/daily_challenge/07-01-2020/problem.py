#Apple

def intersection_(a, b):
  # fill this in.
    return list(set(a) & set(b)) 

class Node(object):
    def __init__(self, val):
        self.val = val
        self.next = None
    def prettyPrint(self):
        c = self
        while c:
            print (c.val)
            c = c.next

a = Node(1)
a.next = Node(2)
a.next.next = Node(3)
a.next.next.next = Node(4)

b = Node(6)
b.next = a.next.next

c = intersection_(a, b)
c.prettyPrint()
# print(c)
# 3 4