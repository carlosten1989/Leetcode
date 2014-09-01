class Solution {
public:
    int trap(int A[], int n) {
        if(n == 0) {
            return 0;
        }
        int l[n];
        int r[n];
        int i;
        int h = 0;
        for(i = 0;i < n;i ++) {
            if(A[i] > h) {
                h = A[i];
            }
            l[i] = h;
        }
        h = 0;
        for(i = n-1;i >= 0;i --) {
            if(A[i] > h) {
                h = A[i];
            }
            r[i] = h;
        }
        int ret = 0;
        for(i = 0;i < n;i ++) {
            ret += min(l[i],r[i]) - A[i];
        }
        return ret;
    }
};
