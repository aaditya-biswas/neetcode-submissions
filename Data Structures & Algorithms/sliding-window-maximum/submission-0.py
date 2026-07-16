
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        q : Deque = deque()
        res : List[int] = []
        for i in range(len(nums)):
            if len(q) != 0 and q[0] <= i- k:
                q.popleft()
            
            if len(q) == 0 or nums[q[-1]] >= nums[i]:
                q.append(i) 
            else:
                while (len(q) > 0 and nums[q[-1]] < nums[i]):
                    q.pop()
                q.append(i)
            
            if i >= k-1:
                res.append(nums[q[0]])
        return res
