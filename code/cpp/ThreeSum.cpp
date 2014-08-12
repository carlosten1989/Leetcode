class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > ret;
        int size = num.size();
        if(size < 3) {
            return ret;
        }
        int i,j,k;
        sort(num.begin(), num.end());
        for(i = 0;i < size-2;i ++) {
            while(i != 0 && num[i] == num[i-1] && i < size - 2) {
                i ++;
            }
            j = i + 1;
            k = size - 1;
            while(j < k) {
                int sum = num[i] + num[j] + num[k];
                if(sum == 0) {
                    vector<int> ans;
                    ans.push_back(num[i]);
                    ans.push_back(num[j]);
                    ans.push_back(num[k]);
                    ret.push_back(ans);
                    j ++;
                    k --;
                } else if(sum < 0) {
                    j ++;
                } else {
                    k --;
                }
                while(j != i + 1 && num[j] == num[j-1] && j < k) {
                    j ++;
                }
                while(k != size - 1 && num[k] == num[k+1] && j < k) {
                    k --;
                }
            }
        }
        return ret;
    }
};