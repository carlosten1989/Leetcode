class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        if(len == 0) {
            return;
        }
        int i = 0;
        while(s[i] == ' ' && i < len) {
            i ++;
        }
        vector<string> tmp;
        int beg = i;
        for(;i < len;i ++) {
            if(s[i] == ' ') {
                tmp.push_back(s.substr(beg,i-beg));
                while(s[i] == ' ' && i < len) {
                    i ++;
                }
                beg = i;
            }
        }
        if(beg != len) {
            tmp.push_back(s.substr(beg,len-beg));
        }
        int size = tmp.size();
        s = "";
        for(i = size - 1;i >= 0;i --) {
            if(i == size - 1) {
                s = tmp[i];
            }
            else {
                s = s + ' ' + tmp[i];
            }
        }
    }
};