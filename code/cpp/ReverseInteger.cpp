class Solution {
public:
    int reverse(int x) {
        bool neg = false;
        if(x < 0) {
            neg = true;
            x = x * -1;
        } 
        int ret = 0;
        while(x) {
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return neg ? ret * -1 : ret;
    }
};