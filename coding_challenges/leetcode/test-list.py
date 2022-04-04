from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        single = ListNode()
        double = ListNode()
        if not head.next:
            print("head val {}".format(head.val))
            return head
        else:
            single = head
            double = head.next
        while not double:
            if single.next:
                single = single.next
                print("single: {}".format(single.val))
                if single.next:
                    
                    double = double.next
                    print("double: {}".format(double.val))
                else:
                    break
        return single

