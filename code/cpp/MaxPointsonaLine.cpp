/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float, int> um;
        int size = points.size();
        if(size <= 1) {
            return size;
        }
        int max_num = 0;
        int i,j;
        for(i = 0;i < size - 1;i ++) {
            um.clear();
            int dup = 1;
            for(j = i+1;j < size;j ++) {
                if(points[i].x == points[j].x && points[i].y == points[j].y) {
                    dup ++;
                    continue;
                }
                float k = points[i].x == points[j].x ? INT_MAX : (float)(points[j].y - points[i].y)/(points[j].x - points[i].x);
                um[k] ++;
            }
            unordered_map<float, int>::iterator it = um.begin();
            for(;it != um.end();it ++) {
                if(it->second + dup > max_num) {
                    max_num = it->second + dup;
                }
            }
            if(dup > max_num) {
                max_num = dup;
            }
        }
        return max_num;
    }
};