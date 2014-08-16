/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool com(const Interval &i, const Interval &j) {
    return i.start < j.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> ret;
        int size = intervals.size();
        sort(intervals.begin(), intervals.end(), com);
        int i;
        for(i = 0;i < size;i ++) {
            if(i == 0) {
                ret.push_back(intervals[i]);
            } else {
                int s = ret.size();
                if(ret[s-1].end >= intervals[i].start) {
                    ret[s-1].end = max(intervals[i].end, ret[s-1].end);
                } else {
                    ret.push_back(intervals[i]);
                }
            }
        }
        return ret;
    }
};