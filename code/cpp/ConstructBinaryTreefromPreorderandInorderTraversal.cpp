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
    TreeNode *buildHelper(vector<int> &preorder, int bp,int ep, vector<int> &inorder, int bi, int ei) {
        if(bp == ep) {
            return new TreeNode(preorder[bp]);
        } else if(bp > ep) {
            return NULL;
        }
        int i;
        TreeNode *root = new TreeNode(preorder[bp]);
        for(i = bi;i <= ei;i ++) {
            if(inorder[i] == preorder[bp]) {
                break;
            }
        }
        root->left = buildHelper(preorder,bp+1,bp+i-bi,inorder,bi,i-1);
        root->right = buildHelper(preorder,bp+i+1-bi,ep,inorder,i+1,ei);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int size = preorder.size();
        if(size == 0)
        {
            return NULL;
        }
        return buildHelper(preorder,0,size-1,inorder,0,size-1);
    }
};