class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1, 0);
        vector<int> tmp(rowIndex+1, 0);
        int i,j;
        for(i = 0;i <= rowIndex;i ++) {
            for(j = 0;j <= i;j ++) {
                if(i == 0) {
                    ret[j] = 1;
                } else if(j == 0) {
                    ret[j] = tmp[j];
                } else if(j == i) {
                    ret[j] = tmp[j-1];
                } else {
                    ret[j] = tmp[j-1] + tmp[j];
                }
            }
            for(j = 0;j <= i;j ++) {
                tmp[j] = ret[j];
            }
        }
        return ret;
    }
};