class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1) {
            return 0;
        }
        bool down = false;
        bool up = false;
        int ret = 0;
        int buy = 0;
        if(prices[0] < prices[1]) {
            up = true;
            buy = prices[0];
        } else {
            down = true;
        }
        int i;
        for(i = 1;i < size - 1;i ++) {
            if(prices[i] < prices[i+1]) {
                if(down) {
                    buy = prices[i];
                    down = false;
                    up = true;
                }
            } else if(prices[i] > prices[i+1]) {
                if(up) {
                    ret += prices[i] - buy;
                    down = true;
                    up = false;
                }
            }
        }
        if(up) {
            ret += prices[i] - buy;
        }
        return ret;
    }
};