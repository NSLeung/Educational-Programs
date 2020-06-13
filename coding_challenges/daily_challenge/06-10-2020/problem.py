# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2, c = 0):
        # Fill this in: naive solution is O(n) ? largest number given?
        res = ListNode(0)
        sum = 0
        carry = 0
        curr = res
        i = 0
        while(l1!=None or l2 != None or carry!=0):
            val1  = (l1.val if l1 else 0)
            val2  = (l2.val if l2 else 0)
            sum = val1 + val2 + carry
            if(sum>=10):
                sum -= 10
                carry = 1
            else:
                carry = 0
            curr.next = ListNode(sum)
            curr = curr.next
            l1 = None if (l1 == None) else l1.next
            l2 = None if (l2 == None) else l2.next

            print(str(i) + " " + str(sum))
            i+=1
        return res.next
    # Node1 = l1
    # node2= l2
	# Bigger_than_ten = 0
	# Node_arr = []
	# while node1 or node2:
	# 	if node1 and not node2:
	# 		Sum_element = bigger_than_ten + node1.val
	# 	elif not node1 and node2:
	# 		Sum_element = bigger_than_ten + node2.val
	# 	else:
	# 		Sum_element = node1.val + node2.val + bigger_than_ten
	# 	if sum_element >= 10:
	# 		Bigger_than_ten = 1
	# 		Sum_element -= 10
	# 	else:
	# 		Bigger_than_ten = 0
	# 	node_arr.append(new ListNode(sum_element, None))
	
	# for i in len(node_arr) -1:
	# 	Node_arr[i].next = node_arr[i + 1]

	# Return node_arr[0]

l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)

l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)

result = Solution().addTwoNumbers(l1, l2)
while result:
    print result.val,
    result = result.next
# 7 0 8