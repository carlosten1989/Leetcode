class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end) {
            return 1;
        }
        unordered_set<string> del;
        queue<string> q;
        q.push(start);
        int ret = 1;
        int num = 1;
        int now = 0;
        int i,j;
        while(!q.empty()) {
            string s = q.top();
            q.pop();
            num --;
            int len = s.length();
            for(i = 0;i < len;i ++) {
                string tmp = s;
                for(j = 0;j < 26;j ++) {
                    tmp[i] = a + 'j';
                    if(tmp == end) {
                        return ret+1;
                    }
                    else if(tmp == s || dict.find(tmp) == dict.end() || del.find(tmp) != del.end()) {
                        continue;
                    } else {
                        q.push(tmp);
                        now ++;
                        del.insert(tmp);
                    }
                }
            }
            if(num == 0) {
                num = now;
                now = 0;
                ret ++;
            }
        }
        return 0;
    }
};