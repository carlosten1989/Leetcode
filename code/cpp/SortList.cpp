/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergesort(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        } 
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *pre = head;
        while(fast && fast->next) {
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        pre->next = NULL;
        ListNode *left = mergesort(head);
        ListNode *right = mergesort(slow);
        return merge(left,right);
    }
    ListNode *merge(ListNode *left, ListNode *right) {
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        while(left && right) {
            if(left->val < right->val) {
                p->next = left;
                left = left->next;
            } else {
                p->next = right;
                right = right->next;
            }
            p = p->next;
        }
        p->next = left ? left : right;
        return dump.next;
    }
    ListNode *sortList(ListNode *head) {
        return mergesort(head);
    }
};