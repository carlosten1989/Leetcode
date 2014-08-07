class Solution {
public:
    double findHelper(int A[], int m, int B[], int n, int k) {
        if(m > n) {
            return findHelper(B, n, A, m, k);
        }
        if(m == 0) {
            return B[k - 1];
        } else if( k == 1) {
            return min(A[0], B[0]);
        }
        int index_a = min(m, k/2);
        int index_b = k - index_a;
        if(A[index_a - 1] == B[index_b - 1]) {
            return A[index_a - 1];
        } else if(A[index_a - 1] > B[index_b - 1]) {
            return findHelper(A, m, B + index_b, n - index_b, k - index_b);
        } else {
            return findHelper(A + index_a, m - index_a, B, n, k - index_a);
        }
    }
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if(m == 0 && n == 0) {
            return 0;
        }
        int sum = m + n;
        if(sum % 2 == 0) {
            return (findHelper(A, m, B, n, sum / 2) + findHelper(A, m, B, n, sum / 2  + 1)) / 2.0;
        } else {
            return findHelper(A, m, B, n, sum / 2 + 1);
        }
    }
};