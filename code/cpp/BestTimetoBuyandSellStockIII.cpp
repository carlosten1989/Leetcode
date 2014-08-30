class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int size = prices.size();
        int ret = 0;
        if(size <= 1) {
            return ret;
        }
        int l[size],r[size];
        int low = prices[0];
        int i;
        int now = 0;
        for(i = 0;i < size;i ++) {
            low = min(prices[i],low);
            now = max(prices[i]-low,now);
            l[i] = now;
        }
        int high = prices[size-1];
        now = 0;
        for(i = size-1;i >= 0;i --) {
            high = max(prices[i],high);
            now = max(high-prices[i],now);
            r[i] = now;
        }
        for(i = 0;i < size-1;i ++) {
            ret = max(ret,l[i]+r[i+1]);
        }
        ret = max(ret,l[size-1]);
        ret = max(ret,r[0]);
        return ret;
    }
};