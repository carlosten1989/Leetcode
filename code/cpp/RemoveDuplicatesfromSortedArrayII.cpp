class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n <= 1) {
            return n;
        }
        int now = A[0];
        bool dup = false;
        int i;
        int j = 1;
        for(i = 1;i < n;i ++) {
            if(A[i] == now) {
                if(!dup) {
                    dup = true;
                    A[j++] = A[i];
                } else {
                    continue;
                }
            } else {
                A[j++] = A[i];
                dup = false;
                now = A[i];
            }
        }
        return j;
    }
};