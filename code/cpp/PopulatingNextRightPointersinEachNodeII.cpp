/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) {
            return;
        }
        TreeLinkNode *first = NULL;
        TreeLinkNode *n = root;
        while(n) {
            if(n->left) {
                first = n->left;
                break;
            } else if(n->right) {
                first = n->right;
                break;
            }
            n = n->next;
        }
        TreeLinkNode dump = TreeLinkNode(-1);
        TreeLinkNode *p = &dump;
        queue<TreeLinkNode*> q;
        while(n) {
            if(n->left) {
                q.push(n->left);
            } 
            if(n->right) {
                q.push(n->right);
            }
            n = n->next;
        }
        while(!q.empty()) {
            p->next = q.front();
            q.pop();
            p = p->next;
        }
        connect(first);
    }
};