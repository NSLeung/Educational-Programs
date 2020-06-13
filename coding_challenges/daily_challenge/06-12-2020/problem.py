class Solution: 
    def sub(self, s, i, j):
        
        if(i==j):
            return 1
        elif(j==i+1 and s[i] == s[j]):
            return 2
        # if there's a match
        elif(s[i] == s[j]):
            return 2 + self.sub(s, i+1, j-1)
        else:
            return max(self.sub(s, i+1, j), self.sub(s, i, j-1))

    
    def longestPalindrome(self, s):
        # Fill this in.

        # this can be done with backtracking. sub(i,j) is the longest palindrome from i to j
        # The Solution is solved by running sub(0, n-1)
        # return self.sub(s, 0, len(s)-1)

        # DP solution
        
        n = len(s)
        LPS = [[0 for x in range(n)] for x in range(n)]
        for i in range(n):
            LPS[i][i] = 1
        for c in range(2, n+1):
            for i in range(n-c+1):
                j = i + c - 1
                if(c==2 and s[i] == s[j]):
                    LPS[i][j] =  2
                elif(s[i] == s[j]):
                    LPS[i][j] = 2 + LPS[i+1][j-1]
                else:
                    LPS[i][j] = max(LPS[i+1][j], LPS[i][j-1])
        return LPS[0][n-1]
        
        

# Test program
s = "doofood"
print(str(Solution().longestPalindrome(s)))
# racecar