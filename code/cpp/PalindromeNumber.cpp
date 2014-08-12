class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        vector<int> tmp;
        while(x > 0) {
            tmp.push_back(x % 10);
            x /= 10;
        }
        int size = tmp.size();
        int i = 0;
        int j = size - 1;
        while(i < j) {
            if(tmp[i] != tmp[j]) {
                return false;
            }
            i ++;
            j --;
        }
        return true;
    }
};