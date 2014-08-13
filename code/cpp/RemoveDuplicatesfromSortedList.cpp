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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        if(head == NULL) {
            return NULL;
        }
        ListNode *q = head;
        int now;
        bool first = false;
        while(q) {
            if(!first) {
                first = true;
                p->next = q;
                now = q->val
                p = p->next;
            } else {
                if(now != q->val) {
                    p->next = q;
                    now = q->val;
                    p = p->next;
                }
            }
            q = q->next;
        }
        p->next = NULL;
        return dump.next;
    }
};