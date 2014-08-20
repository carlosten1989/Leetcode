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
    int bHelper(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        int left = bHelper(root->left);
        int right = bHelper(root->right);
        if(left == -2 || right == -2) {
            return -2;
        }
        if(abs(left - right) >= 2) {
            return -2;
        } else {
            return max(left,right) + 1;
        }
    }
    bool isBalanced(TreeNode *root) {
        if(root == NULL) {
            return true;
        }
        return (bHelper(root) != -2);
    }
};