class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int len = strlen(s);
        if(len == 0)
        {
            return 0;
        }
        int i;
        int k = len-1;
        while(k >= 0)
        {
            if(s[k] == ' ')
            {
                k --;
            }
            else
            {
                break;
            }
        }
        int ret = 0;
        for(i = k;i >=0;i --)
        {
            if(s[i] == ' ')
            {
                ret = k - i;
                break;
            }
            else if(i == 0)
            {
                ret = k - i + 1;
            }
        }
        return ret;
    }
};