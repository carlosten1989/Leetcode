class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> f;
        int len = s.length();
        if(len == 0) {
            return true;
        }
        int i;
        for(i = 0;i < len;i ++) {
            f.push_back(false);
        }
        int j;
        for(i = 0;i < len;i ++) {
            f[i] = dict.find(s.substr(0,i+1)) != dict.end();
            if(!f[i]) {
                for(j = 0;j < i;j ++) {
                    if(f[j] && dict.find(s.substr(j+1,i-j)) != dict.end()) {
                        f[i] = true;
                        break;
                    }
                }
            }
        }
        return f[len-1];
    }
};