class Solution {
public:
    vector<string> ret;
    void cal(vector<vector<bool> > &f, string s, int index, vector<string> &ans)
    {
        if(index == -1)
        {
            string tmp;
            int size = ans.size();
            for(int j = size - 1;j >= 0;j --)
            {
                tmp += ans[j];
                if(j != 0)
                {
                    tmp += " ";
                }
            }
            ret.push_back(tmp);
            return;
        }
        int i;
        for(i = 0;i <= index;i ++)
        {
            if(f[i][index])
            {
                ans.push_back(s.substr(i,index-i+1));
                cal(f,s,i-1,ans);
                ans.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        ret.clear();
        if(s.length() == 0)
        {
            return ret;
        }
        int len = s.length();
        vector<vector<bool> > f;
        f.clear();
        int i,j;
        for(i = 0;i < len;i ++)
        {
            vector<bool> tmp;
            for(j = 0;j < len;j ++)
            {
                tmp.push_back(false);
            }
            f.push_back(tmp);
        }
        for(i = 0;i < len;i ++)
        {
            for(j = i;j < len;j ++)
            {
                string tmp(s,i,j-i+1);
                if(dict.find(tmp) != dict.end())
                {
                    f[i][j] = true;
                }
            }
        }
        vector<string> ans;
        ans.clear();
        cal(f,s,len-1,ans);
        return ret;
    }
};