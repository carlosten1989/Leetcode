class Solution {
public:
    vector<vector<int> > ret;
    vector<int> use;
    bool check(int index, vector<int> &num) {
        int i;
        int n = num[index];
        for(i = index-1;i >= 0;i --) {
            if(num[i] == n && !use[i]) {
                return false;
            }
        }
        return true;
    }
    void permuteHelper(vector<int> &ans, vector<int> &num, int len, int size) {
        if(len == size) {
            ret.push_back(ans);
            return;
        }
        int i;
        for(i = 0;i < size;i ++) {
            if(use[i] == 0 && check(i,num)) {
                use[i] = 1;
                ans.push_back(num[i]);
                permuteHelper(ans,num,len+1,size);
                ans.pop_back(num[i]);
                use[i] = 0;
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int size = num.size();
        ret.clear();
        if(size == 0) {
            return ret;
        }
        int i;
        sort(num.begin(),num.end());
        use.clear();
        for(i = 0;i < size;i ++) {
            use.push_back(0);
        }
        vector<int> ans;
        permuteHelper(ans,num,0,size);
        return ret;
    }
};