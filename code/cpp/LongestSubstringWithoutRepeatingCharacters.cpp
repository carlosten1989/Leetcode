class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
		if(length <= 1) {
			return length;
		}
		unordered_set<char> us;
		int slow = 0;
		int fast = 0;
        int ret = 0;
		while(fast < length) {
			if(us.find(s[fast]) != us.end()) {
				int len = fast - slow;
                if(len > ret) {
                    ret = len;
                }
                us.erase(s[slow]);
                slow ++;
			} else {
                us.insert(s[fast]);
                fast ++;
            }
		}
        int len = fast - slow;
        if(len > ret) {
            ret = len;
        }
        return ret;
    }
};