#include <vector>
#include <deque>
#include <algorithm>
#include <utility>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        using pt = std::pair<int, int>;
        std::vector<pt> ptintervals;
        for (int i = 0; i < n; ++i) {
            ptintervals.push_back({intervals[i][0], intervals[i][1]});
        }
        
        std::sort(ptintervals.begin(), ptintervals.end());
        
        std::deque<pt> validIntervals;
        validIntervals.push_back(ptintervals[0]);
        
        for (int i = 1; i < n; ++i) {   
            if (ptintervals[i].first >= validIntervals.back().second) {
                validIntervals.push_back(ptintervals[i]);
            }
            else {
                if (ptintervals[i].second > validIntervals.back().second) {
                    continue;
                }
                else {
                    validIntervals.pop_back();
                    validIntervals.push_back(ptintervals[i]);
                }
            }
        }
        
        return n - validIntervals.size();
    }
};