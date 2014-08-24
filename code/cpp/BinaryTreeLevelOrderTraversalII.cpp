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
    vector<vector<int> >ret;
    void levelHelper(TreeNode *root, int level) {
        if(root == NULL) {
            return;
        }
        if(ret.size() == level) {
            vector<int> ans;
            ans.push_back(root->val);
            ret.push_back(ans);
        } else {
            ret[level].push_back(root->val);
        }
        levelHelper(root->left,level+1);
        levelHelper(root->right,level+1);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        ret.clear();
        if(root == NULL) {
            return ret;
        }
        levelHelper(root, 0);
        reverse(ret.begin(),ret.end());
        return ret;
    }
};