from collections import Counter, deque
from heapq import heappush, heappop
from typing import List

class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        # Step 1: Count frequencies of each task
        counts = Counter(tasks)
        
        # Step 2: Build a Max-Heap (Python only has min-heap, so we store negative values)
        max_heap = [-cnt for cnt in counts.values()]
        heapq.heapify(max_heap)
        
        time = 0
        # The queue stores pairs: (remaining_count, time_when_available)
        cooldown_queue = deque()
        
        # Step 3: Simulate the CPU cycles
        while max_heap or cooldown_queue:
            time += 1
            
            # If there's a task available to run, execute it
            if max_heap:
                # Remember, counts are negative in the heap
                cnt = heappop(max_heap) + 1 
                if cnt < 0:
                    # Task still has remaining instances; add to cooldown queue
                    cooldown_queue.append((cnt, time + n))
            
            # Check if any task in the cooldown queue is ready to be put back into the heap
            if cooldown_queue and cooldown_queue[0][1] == time:
                ready_task_cnt, _ = cooldown_queue.popleft()
                heappush(max_heap, ready_task_cnt)
                
        return time