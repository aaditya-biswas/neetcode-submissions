class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Merge the overlapping intervals 
        vector<vector<int>> newIntervals;
        sort(intervals.begin() ,intervals.end());
        for (int i = 0 ; i < intervals.size() ; ++i ) {
            if (newIntervals.size() == 0 || newIntervals.back()[1] < intervals[i][0]) newIntervals.push_back(intervals[i]);
            else newIntervals.back()[1] = max(newIntervals.back()[1],intervals[i][1]);
        }
        return newIntervals;
    } 
};
