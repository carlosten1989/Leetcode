class Solution {
public:
    vector<string> ret;
    bool check(string s) {
        int size = s.length();
        if(size == 1) {
            return s >= "0" && s <= "9";
        } else if(size == 2) {
            return s >= "10" && s <= "99";
        } else {
            return s >= "100" && s <= "255";
        }
    }
    void restoreHelper(string s, vector<string> &ans, int beg, int dep) {
        if(dep == 4 && beg = s.length()) {
            ret.push_back(ans[0] + '.' + ans[1] + '.' + ans[2] + '.' + ans[3]);
            return;
        }
        int i;
        for(i = beg;i < beg+3 && i < s.length();i ++) {
            string tmp(s,beg,i-beg+1);
            if(check(tmp)) {
                ans.push_back(tmp);
                restoreHelper(s,ans,i+1,dep);
                ans.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        ret.clear();
        vector<string> ans;
        restoreHelper(s,ans,0,0);
        return ret;
    }
};