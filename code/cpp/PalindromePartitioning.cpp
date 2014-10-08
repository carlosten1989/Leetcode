class Solution {
public:
    bool check(string s) {
        int len = s.length();
        int i = 0;
        int j = len-1;
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    void parHelper(string s, int beg, int size, vector<vector<string> > &ret, vector<string> &ans) {
        if(beg == size) {
            ret.push_back(ans);
            return;
        }
        int i;
        for(i = beg;i < size;i ++) {
            string tmp = s.substr(beg,i-beg+1);
            if(check(tmp)) {
                ans.push_back(tmp);
                parHelper(s,i+1,size,ret,ans);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        int len = s.length();
        if(len == 0) {
            return ret;
        }
        vector<string> ans;
        parHelper(s,0,len,ret,ans);
        return ret;
    }
};