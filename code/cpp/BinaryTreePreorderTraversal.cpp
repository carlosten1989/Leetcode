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
    void preorderHelper(TreeNode *root)
    {
        if(root == NULL) {
            return;
        }
        ret.push_back(root->val);
        preorderHelper(root->left);
        preorderHelper(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        ret.clear();
        preorderHelper(root);
        return ret;
    }
};