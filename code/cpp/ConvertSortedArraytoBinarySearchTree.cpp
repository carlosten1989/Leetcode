/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortHelper(vector<int> &num, int beg, int end) {
        if(beg > end) {
            return NULL;
        }
        int mid = (beg + end) / 2;
        TreeNode *p = new TreeNode(num[mid]);
        p->left = sortHelper(num, beg, mid - 1);
        p->right = sortHelper(num, mid + 1, end);
        return p;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        int size = num.size();
        if(size == 0) {
            return NULL;
        }
        TreeNode *p = sortHelper(num,0,size-1);
        return p;
    }
};