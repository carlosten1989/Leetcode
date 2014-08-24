class Solution {
public:
    vector<vector<int> > ret;
    void subHelper(vector<int> &s,vector<int> &ans, int beg, int end) {
        ret.push_back(ans);
        if(beg == end) {
            return;
        }
        int i;
        for(i = beg;i < end;i ++) {
            ans.push_back(s[i]);
            subHelper(s,ans,i+1,end);
            ans.pop_back();
        }
    }
    vector<vector<int> > subsets(vector<int> &S) {
        ret.clear();
        vector<int> ans;
        sort(S.begin(),S.end());
        subHelper(S,ans,0,S.size());
        return ret;
    }
};