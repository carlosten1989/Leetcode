class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret = "";
        int size = strs.size();
        if(size == 0) {
            return ret;
        }
        int len = strs[0].length();
        if(len == 0) {
            return ret;
        }
        int i;
        int j;
        for(i = 0;i < len;i ++) {
            if(i) {
                ret.push_back(strs[0][i-1]);
            }
            for(j = 1;j < size;j ++) {
                if(strs[j].length() <= i || strs[j][i] != strs[0][i]) {
                    return ret;
                }
            }
        }
        ret.push_back(strs[0][i-1]);
        return ret;
    }
};