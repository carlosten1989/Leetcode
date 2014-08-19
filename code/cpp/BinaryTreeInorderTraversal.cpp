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
    vector<int> ret;
    void inorderHelper(TreeNode *root)
    {
        if(root == NULL) {
            return;
        }
        inorderHelper(root->left);
        ret.push_back(root->val);
        inorderHelper(root->right);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        ret.clear();
        inorderHelper(root);
        return ret;
    }
};