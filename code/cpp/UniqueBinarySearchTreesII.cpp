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
    vector<TreeNode *> generateHelper(int beg, int end) {
        vector<TreeNode *> ret;
        if(beg > end) {
            ret.push_back(NULL);
            return ret;
        }
        int i,j,k;
        for(i = beg;i <=end;i ++) {
            vector<TreeNode *> left = generateHelper(beg,i-1);
            vector<TreeNode *> right = generateHelper(i+1,end);
            int ls = left.size();
            int rs = right.size();
            for(j = 0;j < ls;j ++) {
                for(k = 0;k < rs;k ++) {
                    TreeNode *root = new TreeNode(i+1);
                    root->left = left[j];
                    root->right = right[k];
                    ret.push_back(root);
                }
            }
        } 
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        return generateHelper(0,n-1);
    }
};