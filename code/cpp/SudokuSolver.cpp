class Solution {
public:
    bool isvalid(int m, int n, vector<vector<char> > &board)
    {
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
        for(i = (m/3)*3;i < (m/3)*3 + 3;i ++) {
            for(j = (n/3)*3;j < (n/3)*3 + 3;j ++) {
                if((i != m || j != n) && board[i][j] == board[m][n]) {
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudokuHelper(vector<vector<char> > &board) {
        int i,j,k;
        for(i = 0;i < 9;i ++) {
            for(j = 0;j < 9;j ++) {
                if(board[i][j] == '.') {
                    for(k = 1;k <= 9;k ++) {
                        board[i][j] = '0' + k;
                        if(isvalid(i,j,board)) {
                            if(solveSudokuHelper(board)) {
                                return true;
                            }
                        }
                        board[i][j] = '.';
                    }
                    return false;
                } 
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelper(board);
    }
};