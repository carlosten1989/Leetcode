class Solution {
public:
    vector<vector<int> > ret;
    void combineHelper(vector<int> ans, vector<int> &candidates,int index, int size, int target) {
        if(target == 0) {
            ret.push_back(ans);
            return;
        }
        if(index == size) {
            return;
        }
        int i;
        int k = target / candidates[index];
        int sum = 0;
        for(i = 0;i <= k;i ++) {
            if(i == 0) {
                combineHelper(ans,candidates,index+1,size,target-sum);
            } else {
                ans.push_back(candidates[index]);
                sum += candidates[index];
                combineHelper(ans,candidates,index+1,size,target-sum);
            }
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        ret.clear();
        int size = candidates.size();
        if(size == 0) {
            return ret;
        }
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        combineHelper(ans,candidates,0,size,target);
        return ret;
    }
};