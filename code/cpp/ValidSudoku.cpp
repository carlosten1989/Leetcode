class Solution {
public:
    bool isvalid(int m, int n, vector<vector<char> > &board) {
        int i,j;
        for(i = 0;i < 9;i ++) {
            if(i != m && board[i][n] == board[m][n]) {
                return false;
            }
        }
        for(j = 0;j < 9;j ++) {
            if(j != n && board[m][j] == board[m][n]) {
                return false;
            }
        }
        for(i = (m/3)*3;i < (m/3)*3+3;i ++) {
            for(j = (n/3)*3;j < (n/3)*3+3;j ++) {
                if((i != m || j != n) && board[i][j] == board[m][n]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char> > &board) {
        int i,j;
        for(i = 0;i < 9;i ++) {
            for(j = 0;j < 9;j ++) {
                if(board[i][j] != '.' && !isvalid(i,j,board)) {
                    return false;
                }
            }
        }
        return true;
    }
};