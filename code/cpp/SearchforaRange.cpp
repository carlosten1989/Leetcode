class Solution {
    
public:
    bool found;
    int beg;
    int end;
    void searchHelper(int A[], int b, int e, int target) {
        if(b > e) {
            return;
        }
        int mid = (b+e) / 2;
        if(A[mid] == target) {
            found = true;
            beg = min(beg,mid);
            end = max(end,mid);
            searchHelper(A,b,mid-1,target);
            searchHelper(A,mid+1,e,target);
        } else if(A[mid] > target) {
            searchHelper(A,b,mid-1,target);
        } else {
            searchHelper(A,mid+1,e,target);
        }
    }
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> ret;
        beg = INT_MAX;
        end = INT_MIN;
        found = false;
        searchHelper(A, 0, n-1, target);
        if(found) {
            ret.push_back(beg);
            ret.push_back(end);
        } else {
            ret.push_back(-1);
            ret.push_back(-1);
        }
        return ret;
    }
};