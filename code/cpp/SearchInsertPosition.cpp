class Solution {
public:
    int bsearch(int A[], int beg, int end, int target) {
        if(beg > end) {
            return beg;
        }
        int mid = (beg + end) / 2;
        if(A[mid] == target) {
            return mid;
        } else if(A[mid] > target) {
            if(mid == 0 || A[mid-1] < target) {
                return mid;
            } else {
                return bsearch(A,beg,mid-1,target);
            }
        } else {
            return bsearch(A,mid+1,end,target);
        }
    }
    int searchInsert(int A[], int n, int target) {
        if(n == 0) {
            return 0;
        }
        return bsearch(A,0,n-1,target);
    }
};