# Given a sorted array, A, with possibly duplicated elements, find the indices of the 
# first and last occurrences of a target element, x. Return -1 if the target is not found.
'''
Input: A = [1,3,3,5,7,8,9,9,9,15], target = 9
Output: [6,8]

Input: A = [100, 150, 150, 153], target = 150
Output: [1,2]

Input: A = [1,2,3,4,5,6,10], target = 9
Output: [-1, -1]
'''
class Solution: 
    def binarySearch(self, arr, l, r, x):
        # base case
        if r >= l:
            mid = l + (r - l)/2
            if(arr[mid] == x):
                # check range here
                left_bound = mid
                right_bound = mid
                while(arr[left_bound] == x):
                    left_bound-=1
                while(arr[right_bound] == x):
                    right_bound+=1
                
                return left_bound+1,right_bound-1
            elif arr[mid] > x:
                return self.binarySearch(arr, l, mid - 1, x)
            else:
                return self.binarySearch(arr, mid + 1, r, x)
        else:
            return -1, -1
    def getRange(self, arr, target):
        # Fill this in.
        # binary search is O(logn)
        return self.binarySearch(arr, 0, len(arr) - 1, target)

  
# Test program 
arr = [1, 2, 2, 2, 2, 3, 4, 7, 8, 8] 
x = 2
print(Solution().getRange(arr, x))
# [1, 4]

arr = [1,3,3,5,7,8,9,9,9,15]
x = 9
print(Solution().getRange(arr, x))

arr = [100, 150, 150, 153]
x = 150
print(Solution().getRange(arr, x))

arr = [1,2,3,4,5,6,10]
x = 9
print(Solution().getRange(arr, x))