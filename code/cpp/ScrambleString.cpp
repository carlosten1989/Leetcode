class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
        {
            return false;
        }
        if(len1 == 0)
        {
            return true;
        }
        bool f[len1][len1][len1];
        int i,j,k;
        for(i = 0;i < len1;i ++)
        {
            for(j = 0;j < len1;j ++)
            {
                if(s1[i] == s2[j])
                {
                    f[0][i][j] = true;
                }
                else
                {
                    f[0][i][j] = false;
                }
            }
        }
        for(k = 1;k < len1;k ++)
        {
            for(i = 0;i < len1 - k;i ++)
            {
                for(j = 0;j < len1 - k;j ++)
                {
                    int m;
                    bool tmp = false;
                    for(m = 0;m < k;m ++)
                    {
                        if((f[m][i][j] && f[k-1-m][i+m+1][j+m+1]) || (f[m][i][j+k-m] && f[k-1-m][i+m+1][j]) )
                        {
                            tmp = true;
                            break;
                        }
                    }
                    f[k][i][j] = tmp;
                }
            }
        }
        return f[len1-1][0][0];
    }
};