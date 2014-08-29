class Solution {
public:
    void sortColors(int A[], int n) {
        if(n <= 1) {
            return;
        }
        int c[3];
        int i;
        for(i = 0;i < 3;i ++) {
            c[i] = 0;
        }
        for(i = 0;i < n;i ++) {
            c[A[i]] ++;
        }
        for(i = 0;i < n;i ++) {
            if(i < c[0]) {
                A[i] = 0;
            } else if(i < c[0]+c[1]) {
                A[i] = 1;
            } else {
                A[i] = 2;
            }
        }
    }
};