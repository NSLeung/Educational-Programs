
# start: 12:10 PM ET
class Solution:
    def isValid(self, s):
    # Fill this in.

    #naive soln: use list as a stack?
        # stack = []
        # n = len(s)
        # if(s == ""):
        #     return True
        # for i in range(n):
        #     if(s[i] == '(' or s[i] == '[' or s[i] == '{'):
        #         stack.append(i)
        #     if(s[i] == ')' or s[i] == ']' or s[i] == '}'):
        #         stack.pop()
        # return True if (stack == []) else False
        
        # try #2
        # d = {}
        # n = len(s)
        # if(s == ""):
        #     return True
        # for i in range(n):
        #     if(s[i] == '('):
        #         try:
        #             d['(']+=1
        #         except:
        #             d['(']=1
        #     elif(s[i] == '['):
        #         try:
        #             d['[']+=1
        #         except:
        #             d['[']=1
        #     elif(s[i] == '{'):
        #         try:
        #             d[ '{']+=1
        #         except:
        #             d[ '{']=1
        #     if(s[i] == ')'):
        #         try:
        #             d['(']-=1
        #         except:
        #             d['(']=-1
        #     elif(s[i] == ']'):
        #         try:
        #             d['[']-=1
        #         except:
        #             d['[']=-1
        #     elif(s[i] == '}'):
        #         try:
        #             d[ '{']-=1
        #         except:
        #             d[ '{']=-1
        # ret = False
        # try:
        #     ret = d['('] == 0
        # except:
        #     ret = True
        # try:
        #     ret = ret and (d['['] == 0)
        # except:
        #     ret = ret and True
        # try:
        #     ret = ret and (d['{'] == 0)
        # except:
        #     ret = ret and True
        # return ret

        #try # 3 (soln from Leetcode)
        # store them seperately, however they must be in the same order
        # because we will use the index to match them
        # since there are only 4 chars in each list => space is O(1)
        open_char = ['(','[','{']
        close_char= [')',']','}']
        # use stack to keep track of the open
        stack = []
        # iterate char in the string
        for ch in s:
            # if char in the open list ==> add into the stack
            if ch in open_char:
                stack.append(ch)
            # if char in the close list ==> verify and match to the top char of the stack
            if ch in close_char:
                # stack is empty, return false right away
                if not stack:
                    return False 
                # find the index of both from the lists above
                close_index = close_char.index(ch)
                open_index = open_char.index(stack.pop())
                # are they the same ?
                if close_index != open_index:
                    return False 
        # stack MUST BE EMPTY ==> they all match
        if stack:
            return False 
        else:
            return True

# Test Program
s = "()(){(())" 
# should return False
print(Solution().isValid(s))

s = ""
# should return True
print(Solution().isValid(s))

s = "([{}])()"
# should return True
print(Solution().isValid(s))

s = "([)]"
# should return False
print(Solution().isValid(s))