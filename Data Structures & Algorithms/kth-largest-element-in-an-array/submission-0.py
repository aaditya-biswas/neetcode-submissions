import heapq as heap
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        kth_largest : List[int] = []
        for a in nums:
            heap.heappush(kth_largest, a)
            if (len(kth_largest) > k):
                heap.heappop(kth_largest)
        return kth_largest[0]