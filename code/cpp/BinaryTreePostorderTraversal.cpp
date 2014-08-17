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
    void postHelper(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        postHelper(root->left);
        postHelper(root->right);
        ret.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        ret.clear();
        postHelper(root);
        return ret;
    }
};