/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    using pt = pair<int, int>;
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pt> new_intervals;
        for (const Interval & interval : intervals ){
            new_intervals.push_back({interval.start , interval.end});
        }
        sort(new_intervals.begin() , new_intervals.end());
        for (int i = 1; i < intervals.size() ; ++i) {
            if (new_intervals[i].first >= new_intervals[i-1].second) {
                continue;
            }
            else  {
                return false;
            }
        } 
        return true;
    }
};
