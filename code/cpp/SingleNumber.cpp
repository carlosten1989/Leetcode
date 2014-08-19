class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        int i;
        for(i = 0;i < n;i ++) {
        	ret ^= A[i];
        }
        return ret;
    }
};