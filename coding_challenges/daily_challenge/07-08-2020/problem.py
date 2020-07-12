import heapq
from heapq import heappush, heappop, heapify  
  
# heappop - pop and return the smallest element from heap 
# heappush - push the value item onto the heap, maintaining 
#             heap invarient 
# heapify - transform list into heap, in place, in linear time 
  
# A class for Min Heap 
class MinHeap: 
      
    # Constructor to initialize a heap 
    def __init__(self): 
        self.heap = []  
  
    def parent(self, i): 
        return (i-1)/2
      
    # Inserts a new key 'k' 
    def insertKey(self, k): 
        heappush(self.heap, k)            
  
    # Decrease value of key at index 'i' to new_val 
    # It is assumed that new_val is smaller than heap[i] 
    def decreaseKey(self, i, new_val): 
        self.heap[i]  = new_val  
        while(i != 0 and self.heap[self.parent(i)] > self.heap[i]): 
            # Swap heap[i] with heap[parent(i)] 
            self.heap[i] , self.heap[self.parent(i)] = ( 
            self.heap[self.parent(i)], self.heap[i]) 
              
    # Method to remove minium element from min heap 
    def extractMin(self): 
        return heappop(self.heap) 
  
    # This functon deletes key at index i. It first reduces 
    # value to minus infinite and then calls extractMin() 
    def deleteKey(self, i): 
        self.decreaseKey(i, float("-inf")) 
        self.extractMin() 
  
    # Get the minimum element from the heap 
    def getMin(self): 
        return self.heap[0] 
  
# Driver pgoratm to test above function 
heapObj = MinHeap() 
heapObj.insertKey(3) 
heapObj.insertKey(2) 
heapObj.deleteKey(1) 
heapObj.insertKey(15) 
heapObj.insertKey(5) 
heapObj.insertKey(4) 
heapObj.insertKey(45) 
  
# print heapObj.extractMin(), 
# print heapObj.getMin(), 
# heapObj.decreaseKey(2, 1) 
# print heapObj.getMin()



def findKthLargest(nums, k):
    # Fill this in.
    # method 1: sort and access : O(nlogn)

    # method 2: minHeap and pop O(k + (n-k)logk)
    # python heapq first element is always smallest
    heap = nums[:k]
    heapq.heapify(heap) # create min heap, this takes O(k)

    # loop runs (n-k times)
    for num in nums[k:]:
        # constant time comparison, if item is smaller than the kth largest
        # seen so far, it is never put on the heap
        if num > heap[0]:
            heapq.heapreplace(heap, num) # log(k) insert/delete
            # or heapq. heappushpop
    return heap[0]
print findKthLargest([3, 5, 2, 4, 6, 8], 3)
# 5