/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if(head == NULL) {
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = NULL;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode *node = new TreeNode(slow->val);
        if(pre) {
            pre->next = NULL;
            node->left = sortedListToBST(head);
        } else {
            node->left = NULL;
        }
        node->right = sortedListToBST(slow->next);
        return node;
    }
};