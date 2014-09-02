class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size <= 1) {
            return 0;
        }
        int ret = 0;
        int i = 0;
        int j = size-1;
        while(i < j) {
            int now = (j-i) * min(height[i],height[j]);
            ret = max(now,ret);
            if(height[i] < height[j]) {
                int k = i;
                i ++;
                while(i < j && height[k] > height[i]) {
                    i ++;
                }
            } else {
                int k = j;
                j --;
                while(i < j && height[k] > height[j]) {
                    j --;
                }
            }
        }
        return ret;
    }
};