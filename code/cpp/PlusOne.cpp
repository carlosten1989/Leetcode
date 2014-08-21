class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> ret;
        int size = digits.size();
        if(size == 0) {
            return ret;
        }
        int i;
        int carry = 0;
        for(i = size-1;i >= 0;i --) {
            if(i == size-1) {
                digits[i] ++;
            }
            digits[i] += carry;
            carry = digits[i] >= 10 ? 1 : 0;
            digits[i] = digits[i] >= 10 ? digits[i] - 10 : digits[i];
        }
        if(carry > 0) {
            ret.push_back(1);
        }
        for(i = 0;i < size;i ++) {
            ret.push_back(digits[i]);
        }
        return ret;
    }
};