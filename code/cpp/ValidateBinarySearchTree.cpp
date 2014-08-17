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
    bool validHelper(TreeNode *root, int left, int right)
    {
        if(root == NULL) {
            return true;
        }
        if(left > root->val || right < root->val) {
            return false;
        }
        return validHelper(root->left, left, root->val) && validHelper(root->right, root->val, right);
    }
    bool isValidBST(TreeNode *root) {
        return validHelper(root,INT_MIN,INT_MAX);
    }
};