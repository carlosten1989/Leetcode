class Solution {
public:
    bool canJump(int A[], int n) {
        if(n <= 1) {
            return true;
        }
        int i;
        int far = A[0];
        for(i = 0;i <= far;i ++) {
            if(i + A[i] > far) {
                far = i + A[i];
            }
            if(far >= n-1) {
                return true;
            }
        }
        return false;
    }
};