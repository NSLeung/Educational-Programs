# start_time: 9:34 PM ET
class Solution:
    # subproblem:
    # def sub(self, s, x):
        
    #     if(0==len(s)):
    #         return 0
    #     # print("called for str[" + str(i) +  "]: " + s[i] + " str[" + str(j) +  "]: " + s[j])
    #     m = 0
    #     # if the characters do not match, keep incrementing the idx i along the string
    #     # while keeping j stationary (max in original call explores both possibilities), with j
    #     # also moving forward 
    #     if(s[0] == x):
    #         # print("same! " + s[i] + " is same as " + s[j])
    #         m = self.sub(s[1:], s[0])
    #     else:
    #         # print("unique! " + s[i] + " is different than " + s[j])
    #         m = max(self.sub(s[1:], s[0]), 1 + self.sub(s[1:], s[0]))
    #     return m
    def lengthOfLongestSubstring(self, string):
    #     return self.sub(s, '-1')
    # Fill this in.
    # similar to a backtracking problem: subproblem(i, j), length of longest
    # substring A[i..n] not matching A[j] Solve for sub(1,0)


    # Creating a dictionary to store the last positions of occurrence 
        seen = {} 
        maximum_length = 0
    
        # starting the inital point of window to index 0 
        start = 0 
        
        for idx in range(len(string)): 
    
            # Checking if we have already seen the element or not 
            if string[idx] in seen: 
    
                # If we have seen the number, move the start pointer 
                # to position after the last occurrence 
                start = max(start, seen[string[idx]] + 1) 
    
            # Updating the last seen value of the character 
            seen[string[idx]] = idx 
            maximum_length = max(maximum_length, idx-start + 1) 
        return maximum_length 


# print Solution().lengthOfLongestSubstring('abrkaabcdefghijjxxx')
# 10
print Solution().lengthOfLongestSubstring('abrkaabc')
#4
