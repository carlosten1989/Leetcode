class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1) {
            return n;
        }
        int i,j=0;
        int now = A[0];
        A[j++] = now;
        for(i = 1;i < n;i ++) {
            if(A[i] == now) {
                continue;
            } else {
                A[j++] = A[i];
                now = A[i];
            }
        }
        return j;
    }
};