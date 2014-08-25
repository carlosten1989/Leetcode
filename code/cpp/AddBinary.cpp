class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() == 0) {
            return b;
        } else if(b.length() == 0) {
            return a;
        }
        int lena = a.length();
        int lenb = b.length();
        int carry = 0;
        int sum = 0;
        string ret;
        int i = lena - 1;
        int j = lenb - 1;
        while(i >= 0 && j >= 0) {
            sum = (a[i] - '0') + (b[j] - '0') + carry;
            carry = sum > 1 ? 1 : 0;
            sum = sum > 1 ? sum - 2 : sum;
            ret = sum == 0 ? '0' + ret : '1' + ret;
            i --;
            j --;
        }
        while(i >= 0) {
            sum = (a[i] - '0') + carry;
            carry = sum > 1 ? 1 : 0;
            sum = sum > 1 ? sum - 2 : sum;
            ret = sum == 0 ? '0' + ret : '1' + ret;
            i --;
        }
        while(j >= 0) {
            sum = (b[j] - '0') + carry;
            carry = sum > 1 ? 1 : 0;
            sum = sum > 1 ? sum - 2 : sum;
            ret = sum == 0 ? '0' + ret : '1' + ret;
            j --;
        }
        if(carry) {
            ret = '1' + ret;
        }
        return ret;
    }
};