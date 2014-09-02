class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char> s;
        int len = s.length();
        if(len == 0) {
            return 0;
        }
        int now = 0;
        int ret = 0;
        int lasi = 0;
        int i = 0;
        while(i < len) {
            if(s[i] == '(') {
                s.push(i);
            } else {
                if(s.empty()) {
                    lasti = i+1;
                } else {
                    s.pop();
                    if(s.empty()) {
                        ret = max(ret,i-lasti+1);
                    } else {
                        now = s.top();
                        ret = max(ret,i-now);
                    }
                }
            }
            i ++;
        }
        return ret;
    }
};