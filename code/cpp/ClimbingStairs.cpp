class Solution {
public:
    int climbStairs(int n) {
        if(n == 0)
        {
            return 0;
        }
        if(n == 1)
        {
            return 1;
        }
        int f[n];
        f[0] = 1;
        f[1] = 2;
        int i;
        for(i = 2;i < n;i ++)
        {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n-1];
    }
};