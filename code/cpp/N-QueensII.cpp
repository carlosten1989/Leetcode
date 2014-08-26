class Solution {
public:
    int ret;    
    int* use;
    int** board;
    bool check(int m, int index, int n) {
        int i;
        for(i = 0;i < index;i ++) {
            int d = index - i;
            if((m - d >= 0 && board[i][m-d] == 1) || (m + d < n && board[i][m+d] == 1)) {
                return false;
            }
        }
        return true;
    }
    void checkHelper(int index, int n) {
        if(index == n) {
            ret ++;
            return;
        }
        int i;
        for(i = 0;i < n;i ++) {
            if(!use[i] && check(i,index,n)) {
                use[i] = 1;
                board[index][i] = 1;
                checkHelper(index+1,n);
                board[index][i] = 0;
                use[i] = 0;
            }
        }
    }
    int totalNQueens(int n) {
        if(n <= 1) {
            return n;
        }
        int i,j;
        ret = 0;
        use = new int[n];
        board = new int*[n];
        for(i = 0;i < n;i ++) {
            use[i] = false;
            board[i] = new int[n];
            for(j = 0;j < n;j ++) {
                board[i][j] = 0;
            }
        }
        checkHelper(0,n);
        return ret;
    }
};