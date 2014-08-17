class Solution {
public:
    vector<vector<int> > ret;
    vector<int> use;
    bool check(int index, vector<int> &s) {
        int n = s[index];
        int i;
        for(i = index-1;i >= 0;i --) {
            if(s[i] == n && use[i] == 0) {
                return false;
            }
        }
        return true;
    }
    void subsetHelper(vector<int> &s, vector<int> &ans, int beg, int size) {
        ret.push_back(ans);
        int i;
        for(i = beg;i < size;i ++) {
            if(use[i] == 0 && check(i,s)) {
                use[i] = 1;
                ans.push_back(s[i]);
                subsetHelper(s,ans,i+1,size);
                ans.pop_back();
                use[i] = 0;
            }
        }
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
         int size = S.size();
         ret.clear();
         if(size == 0) {
            return ret;
         }
         sort(S.begin(), S.end());
         int i;
         vector<int> ans;
         for(i = 0;i < size;i ++) {
            use.push_back(0);
         }
         subsetHelper(S,ans,0,size);
         return ret;
    }
};