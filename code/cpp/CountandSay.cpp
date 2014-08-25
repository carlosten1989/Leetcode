class Solution {
public:
    string countAndSay(int n) {
        string ret;
        if(n == 0) {
        	return ret;
        } else if(n == 1) {
        	return "1";
        }
        ret = "1";
        int i,j;
        for(i = 2;i <= n;i ++) {
        	int len = ret.length();
        	int count = 0;
        	int first = 0;
        	char now;
        	string tmp;
        	for(j = 0;j < len;j ++) {
        		if(first == 0) {
        			first = 1;
        			count = 1;
        			now = ret[j];
        		} else if(now == s[j]) {
        			count ++;
        		} else {
        			char c = ('0' + count);
        			tmp += c;
        			tmp += now;
        			count = 1;
        			now = ret[j];
        		}
        	}
        	char c = ('0' + count);
        	tmp += c;
        	tmp += now;
        	ret = tmp;
        }
        return ret;
    }
};