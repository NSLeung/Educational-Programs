from collections import OrderedDict
# Given a list of numbers with only 3 
# unique numbers (1, 2, 3), sort the list in O(n) time.
def sortNums(nums):
    # Fill this in.
    # ideas: tweak an existing sorting algorithm (probably need to look up)
    # idea 2 : use a special data structure
    # can't assume given positive integers
    d = {}
    ret = []
    # d[str(-1)] = 30
    # print(d["-1"])
    # d[-1] = 30
    # print(d[-1])

    # O(n)
    for i in range(len(nums)):
        try:
            d[nums[i]] += 1
        except:
            d[nums[i]] = 1
    
    # print sorted dictionary, unfortunately this takes O(nlogn) -> Timsort
    # but sorting constant 3 keys is quick?!
    for keys, val in sorted(d.items()):
        # print (keys,val)
        while(d[keys] != 0):
            ret.append(keys)
            d[keys] -= 1
        # approach #2 - traverse initial list, keep track of beginning and end
    # indices of the nonunique number and insert to resulting array in sorted manner

    # approach #3 - keep approahc #1 main idea, but maintain another structure for
    # the order (this is manipulated in constant time because there are only 3 unique
    # entries )

    return ret
# Function to print array 
def printArray( a): 
    for k in a: 
        print (k)
#dutch national flag problem (Dijkstra!)
def dutchBois(a):
    # array = [3, 3, 2, 1, 3, 2, 1]
    lo = 0
    hi = len(a) - 1
    mid = 0
    while mid <= hi: 
        if a[mid] == 1: 
            # swap
            a[lo], a[mid] = a[mid], a[lo] 
            lo = lo + 1
            mid = mid + 1
            print("a[mid] == 1")
            # printArray(a)
            print(a)
        elif a[mid] == 2: 
            mid = mid + 1
            print("a[mid] == 2")
            # printArray(a)
            print(a)
        else: 
            a[mid], a[hi] = a[hi], a[mid]  
            hi = hi - 1
            print("else")
            # printArray(a)
            print(a)
    return a 
def test(nums):
    for i in range(len(nums)):
        index_three = len(nums)-1
        Index_one = 0
        if nums[i] == 3:
            nums[i], nums[Index_one] = nums[len(nums) - 1], nums[i]
            index_three -= 1
        if nums[i] == 1:
            nums[i], nums[Index_one] = nums[Index_one], nums[i]
            Index_one += 1
    return nums
    
        
# example
Input = [3, 3, 2, 1, 3, 2, 1]
# Output: [1, 1, 2, 2, 3, 3, 3]
# print (sortNums([3, 3, 2, 1, 3, 2, 1]))

print(Input)
# print(dutchBois(Input))
print(test(Input))
# [1, 1, 2, 2, 3, 3, 3]