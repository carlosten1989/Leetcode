/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
public:
    int sum = 0;
    void sumHelper(TreeNode *root,int psum)
    {
        if(root == NULL) {
            return;
        }
        psum = 10 * psum + root->val;
        if(root->left == NULL && root->right == NULL) {
            sum += psum;
        } 
        if(root->left != NULL) {
            sumHelper(root->left,psum);
        }
        if(root->right != NULL) {
            sumHelper(root->right,psum);
        }
    }
    int sumNumbers(TreeNode *root) {
        sum = 0;
        sumHelper(root,0);
        return sum;
    }
};