class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int size = num.size();
        if(size < 3) {
            return target;
        }
        sort(num.begin(), num.end());
        int i,j,k;
        int ret = 9999999;
        for(i = 0;i < size - 2;i ++) {
            while(i != 0 && i < size - 2 && num[i] == num[i-1]) {
                i ++;
            }
            j = i + 1;
            k = size - 1;
            while(j < k) {
                int sum = num[i] + num[j] + num[k];
                int r = abs(sum - target);
                if(r == 0) {
                    return sum;
                } 
                if(r < abs(ret - target)) {
                    ret = sum;
                }
                if(target > sum) {
                    j ++;
                } else {
                    k --;
                }
                while(j != i+1 && j < k && num[j] == num[j-1]) {
                    j ++;
                }
                while(k != size-1 && j < k && num[k] == num[k+1]) {
                    k --;
                }
            }
        }
        return ret;
    }
};