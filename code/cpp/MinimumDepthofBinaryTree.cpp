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
    int depth = INT_MAX;
    void minHelper(TreeNode *root, int d) {
        if(root->left == NULL && root->right == NULL) {
            if(d < depth) {
                depth = d;
            }
        }
        if(root->left != NULL) {
            minHelper(root->left, d+1);
        }
        if(root->right != NULL) {
            minHelper(root->right, d+1);
        }
    }
    int minDepth(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        minHelper(root, 1);
        return depth;
    }
};