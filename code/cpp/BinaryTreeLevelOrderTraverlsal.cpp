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
    vector<vector<int> > ret;
    void levelHelper(TreeNode *root, int level) {
        if(root == NULL) {
            return;
        }
        if(ret.size() == level) {
            vector<int> tmp;
            tmp.push_back(root->val);
            ret.push_back(tmp);
        } else {
            ret[level].push_back(root->val);
        }
        levelHelper(root->left, level + 1);
        levelHelper(root->right, level + 1);
    }
    vector<vector<int> > levelOrder(TreeNode *root) {
        ret.clear();
        levelHelper(root, 0);
        return ret;
    }
};