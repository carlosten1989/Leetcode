class Solution {
public:
    bool searchHelper(int A[], int beg, int end, int target) {
        if(beg > end) {
            return false;
        }
        int mid = (beg + end) / 2;
        if(A[mid] == target) {
            return true;
        }
        if(A[beg] < A[end]) {
            return A[mid] > target ? searchHelper(A,beg,mid-1,target) : searchHelper(A,mid+1,end,target);
        }
        if(A[beg] < A[mid]) {
            if(target >= A[beg] && target < A[mid]) {
                return searchHelper(A,beg,mid-1,target);
            } else {
                return searchHelper(A,mid+1,end,target);
            }
        } else if(A[mid] < A[beg]) {
            if(target > A[mid] && target <= A[end]) {
                return searchHelper(A,mid+1,end,target);
            } else {
                return searchHelper(A,beg,mid-1,target);
            }
        } else {
            if(A[mid] != A[end]) {
                return searchHelper(A,mid+1,end,target);
            } else {
                return searchHelper(A,beg,mid-1,target) || searchHelper(A,mid+1,end,target);
            }
        }
    }
    bool search(int A[], int n, int target) {
        return searchHelper(A,0,n-1,target);
    }
};