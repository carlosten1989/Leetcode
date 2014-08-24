class Solution {
public:
    vector<vector<int> > ret;
    void combineHelper(vector<int> &ans, int n, int k,int index) {
        if(k == 0) {
            ret.push_back(ans);
            return;
        }
        int i;
        for(i = index;i <= n;i ++) {
            ans.push_back(i);
            combineHelper(ans,n,k-1,i+1);
            ans.pop_back();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        ret.clear();
        vector<int> ans;
        ans.clear();
        combineHelper(ans, n, k, 1);        
        return ret;
    }
};