/**
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
**/

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n == 0) {
            return 0;
        }
        int ret = A[0];
        int i;
        int now;
        for(i = 0;i < n;i ++) {
            now = now + A[i];
            if(now > ret) {
                ret = now;
            }
            if(now < 0) {
                now = 0;
            }
        }
        return ret;
    }
};