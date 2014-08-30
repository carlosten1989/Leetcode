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
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        ListNode *pre = head;
        ListNode *q = head;
        while(q && q->next) {
            pre = q;
            q = q->next;
            p->next = q;
            ListNode *tmp = q->next;
            q->next = pre;
            p = pre;
            q = tmp;
        }
        p->next = q;
        return dump.next;
    }
};