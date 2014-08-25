class Solution {
public:
    double pow(double x, int n) {
        if(n == 0) {
            return 1.0;
        }
        if(n < 0) {
            if(n == INT_MIN) {
                return 1.0 / (pow(x,INT_MAX) * x);
            } else {
                return 1.0 / pow(x,-n);
            }
        } else {
            double half = pow(x,n/2);
            if(n % 2) {
                return half * half * x;
            } else {
                return half * half;
            }
        }
    }
};