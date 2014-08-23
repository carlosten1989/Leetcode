class Solution {
public:
    vector<string> ret;
    void generateHelper(string ans, int left, int right, int n) {
        if(right == n) {
            ret.push_back(ans);
            return;
        }
        if(left == right) {
            ans.push_back('(');
            generateHelper(ans,left+1,right,n);
        } else if(left == n) {
            ans.push_back(')');
            generateHelper(ans,left,right+1,n);
        } else {
            ans.push_back('(');
            generateHelper(ans,left+1,right+1,n);
            ans.pop_back();
            ans.push_back(')');
            generateHelper(ans,left,right+1,n);
        }

    }
    vector<string> generateParenthesis(int n) {
        ret.clear();
        if(n == 0) {
            return ret;
        }
        string ans;
        generateHelper(ans, 0, 0, n);
        return ret;
    }
};