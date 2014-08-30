class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int size = num.size();
        if(size <= 1) {
            return size;
        }
        unordered_set<int> us;
        int i;
        for(i = 0;i < size;i ++) {
            us.insert(num[i]);
        }
        int now = 1;
        int max_num = 1;
        for(i = 0;i < size;i ++) {
            if(us.find(num[i]) != us.end()) {
                us.erase(num[i]);
                now = 1;
                int l = num[i] + 1;
                while(us.find(l) != us.end()) {
                    us.erase(l);
                    now ++;
                    l ++;
                }
                l = num[i] - 1;
                while(us.find(l) != us.end()) {
                    us.erase(l);
                    now ++;
                    l --;
                }
            }
            max_num = max(max_num,now);
        }
        return max_num;
    }
};