class Solution {
public:
    bool isScramble(string s1, string s2) {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2) {
            return false;
        }
        if(len1 == 0) {
            return true;
        }
        int len = len1;
        bool f[len][len][len];
        int i,j,k;
        for(i = 0;i < len;i ++) {
            for(j = 0;j < len;j ++) {
                f[0][i][j] = s1[i] == s2[j];
            }
        }
        for(k = 1;k < len;k ++) {
            for(i = 0;i < len-k;i ++) {
                for(j = 0;j < len-k;j ++) {
                    int m;
                    bool tmp = false;
                    for(m = 0;m < k;m ++) {
                        if((f[m][i][j] && f[k-1-m][i+m+1][j+m+1]) || (f[m][i][j+k-m] && f[k-1-m][i+m+1][j])) {
                            tmp = true;
                            break;
                        }
                    }
                    f[k][i][j] = tmp;
                }
            }
        }
        return f[len-1][0][0];
    }
};