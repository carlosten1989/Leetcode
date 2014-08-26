class Solution {
public:
    vector<vector<string> > ret;
    bool *use;
    bool check(vector<string> &ans, int index, int p) {
        int i;
        for(i = 0;i < index;i ++) {
            int d = index - i;
            if((p-d >= 0 && ans[i][p-d] == 'Q') || (p+d < ans.size() && ans[i][p+d] == 'Q')) {
                return false;
            }
        }
        return true;
    }
    void solveHelper(vector<string> &ans, int index, int n) {
        if(index == n) {
            ret.push_back(ans);
            return;
        }
        int i;
        for(i = 0;i < n;i ++) {
            if(!use[i] && check(ans,index,i)) {
                use[i] = true;
                ans[index][i] = 'Q';
                solveHelper(ans,index+1,n);
                ans[index][i] = '.';
                use[i] = false;
            }
        }
    }
    vector<vector<string> > solveNQueens(int n) {
        ret.clear();
        if(n == 0) {
            return ret;
        }
        int i,j;
        use = new bool[n];
        vector<string> ans;
        for(i = 0;i < n;i ++) {
            use[i] = false;
            string tmp;
            for(j = 0;j < n;j ++) {
                tmp.push_back('.');
            }
            ans.push_back(tmp);
        }
        solveHelper(ans,0,n);
        return ret;
    }
};