class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &ans, vector<bool> &used, vector<int> &num, int now, int size) {
        if(now == size) {
            ret.push_back(ans);
        }
        int i;
        for(i = 0;i < size;i ++) {
            if(!used[i]) {
                ans.push_back(num[i]);
                used[i] = true;
                dfs(ans,used,num,now+1,size);
                used[i] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        int size = num.size();
        ret.clear();
        if(size == 0) {
            return ret;
        }
        vector<bool> used;
        int i;
        for(i = 0;i < size;i ++) {
            used.push_back(false);
        }
        vector<int> ans;
        dfs(ans, used, num, 0, size);
        return ret;
    }
};