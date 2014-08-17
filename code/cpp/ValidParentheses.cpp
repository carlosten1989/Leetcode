class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if(len % 2) {
            return false;
        }
        stack<char> ss;
        int i;
        for(i = 0;i < len;i ++) {
            if(s[i] == ')') {
                if(ss.empty() || ss.top() != '(') {
                    return false;
                }
                ss.pop();
            } else if(s[i] == ']') {
                if(ss.empty() || ss.top() != '[') {
                    return false;
                }
                ss.pop();
            } else if(s[i] == '}') {
                if(ss.empty() || ss.top() != '{') {
                    return false;
                }
                ss.pop();
            }
            else {
                ss.push(s[i]);
            }
        }
        return ss.empty();
    }
};