class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        if(n == 0) {
            return n;
        }
        int i;
        int count = 0;
        for(i = 0;i < n;i ++) {
            if(A[i] != elem) {
                A[count++] = A[i];
            }
        }
        return count;
    }
};