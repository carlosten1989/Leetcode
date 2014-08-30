class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int size = num.size();
        if(size <= 1) {
            return;
        }
        int i;
        for(i = size - 2;i >= 0;i --) {
            if(num[i] < num[i+1]) {
                break;
            }
        }
        if(i == -1) {
            reverse(num.begin(),num.end());
            return;
        }
        int j = i + 2;
        for(;j < size;j ++) {
            if(num[j] <= num[i]) {
                break;
            }
        }
        j --;
        swap(num[i],num[j]);
        reverse(num.begin()+i+1, num.end());
    }
};