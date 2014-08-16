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
    int ret = -99999;
    int maxHelper(TreeNode *root) {
        if(root->left == NULL && root->right == NULL) {
            if(root->val > ret) {
                ret = root->val;
            }
            return root->val;
        }
        int left = -99999;
        int right = -99999;
        if(root->left != NULL) {
            left = maxHelper(root->left);
        }
        if(root->right != NULL) {
            right = maxHelper(root->right);
        }
        int sum = root->val;
        int maxsum = max(max(max(sum,sum+left),sum+right),sum+left+right);
        if(maxsum > ret) {
            ret = maxsum;
        }
        return max(max(sum,sum+left),sum+right);
    }
    int maxPathSum(TreeNode *root) {
        if(root == NULL) {
            return 0;
        }
        maxHelper(root);
        return ret;
    }
};