class Solution {
public:
    vector<int> use;
    vector<vector<int> > ret;
    bool check(vector<int> &num, int index)
    {
        int n = num[index];
        int i;
        for(i = index-1;i >= 0;i --) {
            if(num[i] == n && use[i] == 0) {
                return false;
            }
        }
        return true;
    }
    void combineHelper(vector<int> &ans, vector<int> &num, int target, int beg, int size)
    {
        if(target == 0) {
            ret.push_back(ans);
            return;
        }
        int i;
        for(i = beg;i < size;i ++) {
            if(use[i] == 0 && check(num,i) && target >= num[i]) {
                ans.push_back(num[i]);
                use[i] = 1;
                combineHelper(ans,num,target-num[i],i+1,size);
                use[i] = 0;
                ans.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int size = num.size();
        ret.clear();
        if(size == 0) {
            return ret;
        }
        use.clear();
        sort(num.begin(), num.end());
        int i;
        for(i = 0;i < size;i ++) {
            use.push_back(0);
        }
        vector<int> ans;
        combineHelper(ans, num, target, 0, size);
        return ret;
    }
};