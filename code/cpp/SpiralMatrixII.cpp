class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ret;
        if(n == 0) {
            return ret;
        }
        int i,j;
        for(i = 0;i < n;i ++) {
            vector<int> ans;
            for(j = 0;j < n;j ++) {
                ans.push_back(0);
            }
            ret.push_back(ans);
        }
        int n = 1;
        for(i = 0;i < (n+1)/2;i ++) {
            for(j = i;j < n-i;j ++) {
                ret[i][j] = n++;
            }
            for(j = i+1;j < n-i;j ++) {
                ret[j][n-i-1] = n++;
            }
            for(j = n-i-2;j >= i;j --) {
                ret[n-i-1][j] = n++;
            }
            for(j = n-i-2;j > i;j --) {
                ret[j][i] = n++;
            }
        }
        return ret;
    }
};