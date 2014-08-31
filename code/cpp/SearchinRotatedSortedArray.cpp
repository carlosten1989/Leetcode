class Solution {
public:
    int searchHelper(int A[], int beg, int end, int target) {
        if(beg > end) {
            return -1;
        }
        int mid = (beg + end) /2;
        if(A[mid] == target) {
            return mid;
        }
        if(A[beg] > A[end]) {
            if(A[beg] > A[mid]) {
                if(target > A[mid] && target <= A[end]) {
                    return searchHelper(A,mid+1,end,target);
                } else {
                    return searchHelper(A,beg,mid-1,target);
                }
            } else {
                if(target < A[mid] && target >= A[beg]) {
                    return searchHelper(A,beg,mid-1,target);
                } else {
                    return searchHelper(A,mid+1,end,target);
                }
            }
        } else {
            return A[mid] > target ? searchHelper(A,beg,mid-1,target) : searchHelper(A,mid+1,end,target);
        }
    }
    int search(int A[], int n, int target) {
        if(n == 0) {
            return -1;
        }
        return searchHelper(A, 0, n-1, target);
    }
};