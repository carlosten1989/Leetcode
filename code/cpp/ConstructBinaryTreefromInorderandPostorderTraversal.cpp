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
    TreeNode *buildHelper(vector<int> &inorder, int bi, int ei, vector<int> &postorder, int bp, int ep) {
        if(bp == ep) {
            return new TreeNode(postorder[ep]);
        } else if(bp > ep) {
            return NULL;
        }
        int i;
        TreeNode *root = new TreeNode(postorder[ep]);
        for(i = bi;i <= ei;i ++) {
            if(inorder[i] == postorder[ep]) {
                break;
            }
        }
        root->left = buildHelper(inorder,bi,i-1,postorder,bp,bp+i-1-bi);
        root->right = buildHelper(inorder,i+1,ei,postorder,bp+i-bi,ep-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        if(size == 0) {
            return NULL;
        }
        return buildHelper(inorder,0,size-1,postorder,0,size-1);
    }
};