class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int r = 0, n = intervals.size();
        vector<vector<int>> result;
        while (r < n && intervals[r][1] < newInterval[0]) {
            result.push_back(intervals[r]);
            r++;
        }
        if (r == n || intervals[r][0] > newInterval[1]) {
            result.insert(result.begin() + r , newInterval);
        }
        else {
            cout << "YES  " <<endl;
            intervals[r][0]= min(newInterval[0 ],intervals[r][0] );
            intervals[r][1] = max(newInterval[1] , intervals[r][1]);
            while (r < n - 1) {
                if (intervals[r+ 1][0] <= intervals[r][1]) {
                    intervals[r+ 1][0] = intervals[r][0];
                    intervals[r + 1][1]  =  max(intervals[r][1], intervals[r+1][1]);
                } else break;
                r++;
            }
        }
        while (r < n) {
            result.push_back(intervals[r]);
            r++;
        }
        return result;

    }
};
