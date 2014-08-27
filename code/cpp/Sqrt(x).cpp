class Solution {
public:
    int bsearch(int beg, int end, int x) {
        if(beg >= end) {
            return beg * beg > x ? beg -1 : beg;
        }
        int mid = (beg + end) / 2;
        if(mid * mid == x) {
            return mid;
        } else if(mid * mid < x) {
            return bsearch(mid+1,end,x);
        } else {
            return bsearch(beg,mid-1,x);
        }
    }
    int sqrt(int x) {
        if(x <= 1) {
            return x;
        }
        return bsearch(1,46340,x);
    }
};