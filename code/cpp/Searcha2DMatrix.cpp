class Solution {
public:
    bool searchHelper(vector<vector<int> > &matrix, int beg, int end, int target) {
        if(beg > end) {
            return false;
        }
        int mid = (beg+end) / 2;
        int col = mid / matrix[0].size();
        int row = mid % matrix[0].size();
        if(matrix[col][row] == target) {
            return true;
        } else if(matrix[col][row] > target) {
            return searchHelper(matrix,0,mid-1,target);
        } else {
            return searchHelper(matrix,mid+1,end,target);
        }
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m == 0) {
            return false;
        }
        int n = matrix[0].size();
        if(n == 0) {
            return false;
        }
        return searchHelper(matrix,0,m*n-1,target);
    }
};