class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row = matrix.size();
        if(row == 0) {
            return;
        }
        int col = matrix[0].size();
        if(col == 0) {
            return;
        }
        int i,j;
        bool zr,zc;
        zr = false;
        zc = false;
        for(i = 0;i < row;i ++) {
            if(matrix[i][0] == 0) {
                zr = true;
                break;
            }
        }
        for(j = 0;j < col;j ++) {
            if(matrix[0][j] == 0) {
                zc = true;
                break;
            }
        }
        for(i = 1;i < row;i ++) {
            for(j = 1;j < col;j ++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(i = 1;i < row;i ++) {
            if(matrix[i][0] == 0) {
                for(j = 1;j < col;j ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        for(j = 0;j < col;j ++) {
            if(matrix[0][j] == 0) {
                for(i = 1;i < row;i ++) {
                    matrix[i][j] = 0;
                }
            }
        }
        if(zr) {
            for(i = 0;i < row;i ++) {
                matrix[i][0] = 0;
            }
        }
        if(zc) {
            for(j = 0;j < col;j ++) {
                matrix[0][j] = 0;
            }
        }
    }
};