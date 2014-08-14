class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int size = triangle.size();
        if(size == 0) {
            return 0;
        }
        int i,j;
        vector<int> tmp(size, 0);
        vector<int> now(size, 0);
        for(i = 0;i < size;i ++) {
            for(j = 0;j <= i;j ++) {
                if(i == 0) {
                    tmp[j] = triangle[i][j];
                } else if(j == 0) {
                    tmp[j] = triangle[i][j] + now[j];
                } else if(j == i) {
                    tmp[j] = triangle[i][j] + now[j-1]; 
                } else {
                    tmp[j] = now[j] > now[j-1] ? triangle[i][j] + now[j-1] : triangle[i][j] + now[j];
                }
            }
            for(j = 0;j <= i;j ++) {
                now[j] = tmp[j];
            }
        }
        int ret = now[0];
        for(i = 0;i < size;i ++) {
            if(ret > now[i]) {
                ret = now[i];
            }
        }
        return ret;
    }
};