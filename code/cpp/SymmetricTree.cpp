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
    bool symmetric(TreeNode* n1,TreeNode* n2) {
        if((n1 == NULL && n2 != NULL) || (n1 != NULL && n2 == NULL)) {
            return false;
        }
        if(n1 == NULL && n2 == NULL) {
            return true;
        }
        if(n1->val != n2->val) {
            return false;
        }
        return symmetric(n1->left,n2->right) && symmetric(n1->right,n2->left);
    }
    bool isSymmetric(TreeNode *root) {
        return root == NULL ? true : symmetric(root->left,root->right);
    }
};