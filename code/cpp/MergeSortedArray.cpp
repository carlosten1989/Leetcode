class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int l = m + n;
        while(m && n) {
            if(A[m-1] > B[n-1]) {
                A[--l] = A[--m];
            } else {
                A[--l] = B[--n];
            }
        }
        while(n) {
            A[--l] = B[--n];
        }
    }
};