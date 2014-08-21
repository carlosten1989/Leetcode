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
    void pre(TreeNode *node, TreeNode *&last) {
        if(node == NULL) {
            return;
        }
        if(last != NULL) {
            last->right = node;
        }
        last = node;
        TreeNode *right = node->right;
        pre(node->left,last);
        node->left = NULL;
        pre(right,last);
    }
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        pre(root,last);
    }
};