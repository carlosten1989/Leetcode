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
    void recoverHelper(TreeNode *root, TreeNode *&n1, TreeNode *&n2, TreeNode *&pre) {
        if(root == NULL) {
            return;
        }
        recoverHelper(root->left,n1,n2,pre);
        if(pre != NULL) {
            if(pre->val > root->val) {
                if(n1 == NULL) {
                    n1 = pre;
                    n2 = root;
                } else {
                    n2 = root;
                }
            }
        }
        pre = root;
        recoverHelper(root->right,n1,n2,pre);
    }
    void recoverTree(TreeNode *root) {
        if(root == NULL) {
            return;
        }
        TreeNode *n1 = NULL;
        TreeNode *n2 = NULL;
        TreeNode *pre = NULL;
        recoverHelper(root,n1,n2,pre);
        if(n1 != NULL) {
            int tmp = n1->val;
            n1->val = n2->val;
            n2->val = tmp;
        }
    }
};