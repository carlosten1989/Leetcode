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
    void pathHelper(TreeNode *root, vector<int> &ans, int sum) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            if(root->val == sum) {
                ans.push_back(root->val);
                ret.push_back(ans);
                ans.pop_back();
            }
            return;
        }
        ans.push_back(root->val);
        if(root->left != NULL) {
            pathHelper(root->left, ans, sum - root->val);
        }
        if(root->right != NULL) {
            pathHelper(root->right, ans, sum - root->val);
        }
        ans.pop_back();
    }
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        ret.clear();
        vector<int> ans;
        pathHelper(root, ans, sum);
        return ret;
    }
};