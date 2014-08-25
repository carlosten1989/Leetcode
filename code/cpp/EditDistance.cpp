class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        if(m == 0) {
            return n;
        } else if(n == 0) {
            return m;
        }
        int dp[m+1][n+1];
        dp[0][0] = 0;
        for(i = 1;i <= m;i ++) {
            dp[i][0] = i;
        }
        for(j = 1;j <= n;j ++) {
            dp[0][j] = j;
        }
        for(i = 0;i < m;i ++) {
            for(j = 0;j < n;j ++) {
                if(word1[i] == word2[j]) {
                    dp[i+1][j+1] = dp[i][j];
                } else {
                    dp[i+1][j+1] = min(dp[i+1][j],min(dp[i][j],dp[i][j+1]));
                }
            }
        }
        return dp[m][n];
    }
};