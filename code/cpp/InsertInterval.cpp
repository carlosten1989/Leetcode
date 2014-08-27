/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int size = intervals.size();
        int i;
        bool insert = false;
        vector<Interval> ret;
        for(i = 0;i < size;i ++) {
            if(insert) {
                ret.push_back(intervals[i]);
                continue;
            }
            if(intervals[i].end < newInterval.start) {
                ret.push_back(intervals[i]);
            } else if(intervals[i].start > newInterval.end) {
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                insert = true;
            } else {
                newInterval.start = min(intervals[i].start,newInterval.start);
                newInterval.end = max(intervals[i].end,newInterval.end);
            }
        }
        if(!insert) {
            ret.push_back(newInterval);
        }
        return ret;
    }
};