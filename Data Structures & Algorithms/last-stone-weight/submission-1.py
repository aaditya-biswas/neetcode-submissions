import heapq
from typing import List 


class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        # get a max queue
        self.heap = [-a for a in stones]
        # 
        heapq.heapify(self.heap)
        while (len(self.heap) > 1):
            highest : int = -self.heap[0]
            heapq.heappop(self.heap)
            second_highest : int = -self.heap[0]
            heapq.heappop(self.heap)
            if (abs(highest - second_highest) > 0):
                heapq.heappush(self.heap,-abs(highest - second_highest))
        if (len(self.heap) == 1): return -self.heap[0]
        return 0

# from typing import List

# class KthLargest:

#     def __init__(self, k: int, nums: List[int]):
#         self.k = k
#         self.heap = nums
        
#         # 1. Transform the list into a min-heap in-place
#         heapq.heapify(self.heap)
        
#         # 2. Keep only the k largest elements in the heap
#         while len(self.heap) > self.k:
#             heapq.heappop(self.heap)

#     def add(self, val: int) -> int:
#         # 3. Push the new value onto the heap
#         heapq.heappush(self.heap, val)
        
#         # 4. If we exceed size k, pop the smallest element
#         if len(self.heap) > self.k:
#             heapq.heappop(self.heap)
            
#         # 5. Peek at index 0 (the smallest of the k elements, which is the kth largest)
#         return self.heap[0]
