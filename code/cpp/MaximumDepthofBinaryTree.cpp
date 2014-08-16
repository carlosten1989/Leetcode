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
    int d;
    void maxHelper(TreeNode *root,int depth)
    {
        if(root == NULL) {
            return;
        }
        if(depth > d) {
            d = depth;
        }
        maxHelper(root->left, depth+1);
        maxHelper(root->right, depth+1);
    }
    int maxDepth(TreeNode *root) {
        d = 0;
        maxHelper(root,1);
        return d;
    }
};