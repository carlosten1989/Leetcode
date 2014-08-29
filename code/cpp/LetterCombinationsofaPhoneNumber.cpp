class Solution {
public:
    vector<string> ret;
    string d[8] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void letterHelper(string &ans, string &digits, int beg, int end) {
        if(beg == end) {
            ret.push_back(ans);
            return;
        }
        int len = d[beg].length();
        int i;
        for(i = 0;i < len;i ++) {
            ans.push_back(d[beg][i]);
            letterHelper(ans,digits,beg+1,end);
            ans.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        ret.clear();
        if(len == 0) {
            ret.push_back("");
            return ret;
        }
        string ans;
        ans.clear();
        letterHelper(ans,digits,0,len);
        return ret;
    }
};