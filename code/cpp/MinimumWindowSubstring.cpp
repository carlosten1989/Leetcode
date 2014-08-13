class Solution {
public:
    string minWindow(string S, string T) {
        int sizes = S.size();
        int sizet = T.size();
        if(sizes < sizet) {
            return "";
        }
        int s1[256];
        int s2[256];
        int i,j;
        for(i = 0;i < 256;i ++) {
            s1[i] = 0;
            s2[i] = 0;
        }
        for(i = 0;i < sizet;i ++) {
            s1[T[i]] ++;
            s2[T[i]] ++;
        }
        int count = sizet;
        int start = 0;
        j = 0;
        int len = INT_MAX;
        for(i = 0;i < sizes;i ++) {
            if(s1[S[i]] > 0) {
                s2[S[i]] --;
                if(s2[S[i]] >= 0) {
                    count --;
                }
            }
            if(count == 0) {
                while(true) {
                    if(s1[S[j]] > 0) {
                        if(s2[S[j]] < 0) {
                            s2[S[j]] ++;
                        } else {
                            break;
                        }
                    } 
                    j ++;
                }
                if(len > i - j + 1) {
                    len = i - j + 1;
                    start = j;
                }
            }
        }
        if(len == INT_MAX) {
            return "";
        }
        return S.substr(start,len);
    }
};