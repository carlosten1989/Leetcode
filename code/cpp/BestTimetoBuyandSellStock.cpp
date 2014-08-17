class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        if(size <= 1) {
            return 0;
        }
        int i;
        int low = prices[0];
        int ret = 0;
        for(i = 0;i < size;i ++) {
            if(prices[i] < low) {
                low = prices[i];
            }
            if(ret < prices[i] - low) {
                ret = prices[i] - low;
            }
        }
        return ret;
    }
};