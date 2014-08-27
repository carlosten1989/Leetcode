class Solution {
public:
    int jump(int A[], int n) {
        if(n <= 1) {
            return 0;
        }
        int count = 1;
        int maxto = A[0];
        int nowto = A[0];
        int i = 1;
        while(maxto < n-1) {
            count ++;
            while(i <= nowto) {
                if(i + A[i] > maxto) {
                    maxto = i + A[i];
                }
                i ++;
            }
            nowto = maxto;
        }
        return count;
    }
};