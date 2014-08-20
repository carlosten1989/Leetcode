class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        ret.clear();
        int i,j;
        if(numRows == 0) {
            return ret;
        }
        for(i = 0;i < numRows;i ++) {
            vector<int> ans;
            for(j = 0;j <= i;j ++) {
                if(i == 0) {
                    ans.push_back(1);
                } else if(j == 0) {
                    ans.push_back(ret[i-1][j]);
                } else if(j == i) {
                    ans.push_back(ret[i-1][j-1]);
                } else {
                    ans.push_back(ret[i-1][j-1] + ret[i-1][j]);
                }
            }
            ret.push_back(ans);
        }
        return ret;
    }
};