class Solution {
public:
    string intToRoman(int num) {
        int INTs[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string ROMANs[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i;
        string ret = "";
        for(i = 0;i < 13;i ++) {
            while(num >= INTs[i]) {
                num -= INTs[i];
                ret += ROMANs[i];
            }
        }
        return ret;
    }
};