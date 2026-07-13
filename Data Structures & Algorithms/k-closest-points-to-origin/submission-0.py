import heapq as heap
import numpy as np
class Solution:
    def dist(self, a : int, b : int)-> float:
        return pow(a*a + b*b,0.5)
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        self.min_distance  : List[int] = np.argsort([self.dist(a,b) for a,b in points])
        self.res : List[List[int]] = []
        for i in range(k):
            self.res.append([points[self.min_distance[i]][0],points[self.min_distance[i]][1]])
        return self.res

