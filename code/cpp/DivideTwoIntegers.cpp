class Solution {
public:
    int divide(int dividend, int divisor) {
        int neg = -1;
        if(dividend > 0) {
            dividend *= -1;
            neg *= -1;
        }
        if(divisor > 0) {
            divisor *= -1;
            neg *= -1;
        }
        int ret = 0;
        while(dividend <= divisor) {
            int count = -1;
            int sum = divisor;
            while(dividend - sum < sum) {
                sum += sum;
                count += count;
            }
            dividend -= sum;
            ret += count;
        }
        return ret * neg;
    }
};