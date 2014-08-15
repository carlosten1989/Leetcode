class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int size = tokens.size();
        if(size == 0) {
            return 0;
        }
        int i;
        stack<int> s;
        for(i = 0;i < size;i ++) {
            int num1,num2;
            if(tokens[i] == "+") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2+num1);
            } else if(tokens[i] == "-") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2-num1);
            } else if(tokens[i] == "*") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2*num1);
            } else if(tokens[i] == "/") {
                num1 = s.top();
                s.pop();
                num2 = s.top();
                s.pop();
                s.push(num2/num1);
            } else {
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};