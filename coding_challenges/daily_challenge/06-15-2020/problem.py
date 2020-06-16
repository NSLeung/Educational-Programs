class ListNode(object):
    # singly linked list
    def __init__(self, x):
        self.val = x
        self.next = None
    
    # Function to print the list
    def printList(self):
        node = self
        output = '' 
        while node != None:
            output += str(node.val)
            output += " "
            node = node.next
        print(output)

    # Iterative Solution
    def reverseIteratively(self, head):
        # Implement this.

        # ideas
        '''
        O(n)
        (1) Modify in place. can traverse list and make new list with "prev". At the end make tail the head
        '''
        curr = head
        prev = None
        while(curr.next):
            temp = curr
            curr = curr.next
            temp.next = prev
            prev = temp
        curr.next = prev
        head = curr

    # pretty similar to iterative solution
    def reverseUtil(self, curr, prev):           
        # If last node mark it head 
        if curr.next is None : 
            self.head = curr  
              
            # Update next to prev node 
            curr.next = prev 
            return 
          
        # Save curr.next node for recursive call 
        next = curr.next  
        # And update next  
        curr.next = prev 
      
        self.reverseUtil(next, curr) 
    # Recursive Solution      
    def reverseRecursively(self, head):
        if head is None: 
            return 
        self.reverseUtil(head, None) 

# Test Program
# Initialize the test list: 
testHead = ListNode(4)
node1 = ListNode(3)
testHead.next = node1
node2 = ListNode(2)
node1.next = node2
node3 = ListNode(1)
node2.next = node3
testTail = ListNode(0)
node3.next = testTail

print("Initial list: ")
testHead.printList()
# 4 3 2 1 0
# testHead.reverseIterativesly(testHead)
testHead.reverseRecursively(testHead)
print("List after reversal: ")
testTail.printList()
# 0 1 2 3 4