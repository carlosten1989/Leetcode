class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        int m = matrix.size();
        if(m == 0) {
            return ret;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return ret;
        }
        int len = min(m,n);
        int i,j;
        int count = 0;
        for(i = 0;i < len/2;i ++) {
            for(j = i;j <= n-1-i;j ++) {
                ret.push_back(matrix[i][j]);
                count ++;
                if(count == m+n-1) {
                    return ret;
                }
            }
            for(j = i+1;j <= m-1-i;j ++) {
                ret.push_back(matrix[j][n-1-i]);
                count ++;
                if(count == m+n-1) {
                    return ret;
                }
            }
            for(j = n-2-i;j >= i;j --) {
                ret.push_back(matrix[m-1-i][j]);
                count ++;
                if(count == m+n-1) {
                    return ret;
                }
            }
            for(j = m-2-i;j >= i+1;j --) {
                ret.push_back(matrix[j][i]);
                count ++;
                if(count == m+n-1) {
                    return ret;
                }
            }
        }
        return ret;
    }
};
