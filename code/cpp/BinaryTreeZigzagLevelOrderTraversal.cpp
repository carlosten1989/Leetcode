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
    void zigzagHelper(TreeNode *root, int level)
    {
        if(root == NULL)
        {
            return;
        }
        if(ret.size() == level)
        {
            vector<int> tmp;
            tmp.push_back(root->val);
            ret.push_back(tmp);
        }
        else
        {
            ret[level].push_back(root->val);
        }
        zigzagHelper(root->left,level+1);
        zigzagHelper(root->right,level+1);
    }
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        ret.clear();
        if(root == NULL)
        {
            return ret;
        }
        zigzagHelper(root,0);
        int i;
        int size = ret.size();
        for(i = 0;i < size;i ++)
        {
            if(i % 2)
            {
                reverse(ret[i].begin(),ret[i].end());
            }
        }
        return ret;
    }
};