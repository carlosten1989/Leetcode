class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> um;
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        int i;
        int ret = 0;
        um['I'] = 1;
        um['V'] = 5;
        um['X'] = 10;
        um['L'] = 50;
        um['C'] = 100;
        um['D'] = 500;
        um['M'] = 1000;
        i = len-1;
        while(i >= 0) {
            if(i == len - 1) {
                ret += um[s[i]];
            } else {
                if(um[s[i]] >= um[s[i+1]]) {
                    ret += um[s[i]];
                } else {
                    ret -= um[s[i]];
                }
            }
            i --;
        }
        return ret;
    }
};