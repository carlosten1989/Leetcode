class Solution {
public:
    int numTrees(int n) {
        if(n <= 1) {
            return n;
        }
        int dp[n+1];
        dp[0] = 1;
        dp[1] = 1;
        int i,j;
        for(i = 2;i <= n;i ++) {
            dp[i] = 0;
            for(j = 0;j < i;j ++) {
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
        return dp[n];
    }
};