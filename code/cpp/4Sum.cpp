class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int size = num.size();
        vector<vector<int> > ret;
        if(size < 4) {
            return ret;
        }
        int i,j,k,l;
        sort(num.begin(), num.end());
        for(i = 0;i < size-3;i ++) {
            while(i != 0&& num[i] == num[i-1]) {
                i ++;
            }
            for(j = i+1;j < size-2;j ++) {
                while(j != i+1 && num[j] == num[j-1]) {
                    j ++;
                }
                k = j + 1;
                l = size - 1;
                while(k < l) {
                    int sum = num[i] + num[j] + num[k] + num[l];
                    if(sum == target) {
                        vector<int> ans;
                        ans.push_back(num[i]);
                        ans.push_back(num[j]);
                        ans.push_back(num[k]);
                        ans.push_back(num[l]);
                        ret.push_back(ans);
                        l --;
                        k ++;
                        while(k < l && num[l] == num[l+1]) {
                            l --;
                        }
                        while(k < l && num[k] == num[k-1]) {
                            k ++;
                        }
                    } else if(sum > target) {
                        l --;
                        while(k < l && num[l] == num[l+1]) {
                            l --;
                        }
                    } else {
                        k ++;
                        while(k < l && num[k] == num[k-1]) {
                            k ++;
                        }
                    }
                }
            }
        }
        return ret;
    }
};