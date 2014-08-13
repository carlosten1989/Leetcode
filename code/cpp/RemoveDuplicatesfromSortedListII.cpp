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
        ListNode *q = head;
        if(head == NULL) {
            return NULL;
        }
        int now;
        bool dup = false;
        now = q->val;
        q = q->next;
        ListNode *pre = head;
        while(q) {
            if(now == q->val) {
                dup = true;
            } else {
                if(!dup) {
                    p->next = pre;
                    p = p->next;
                }
                dup = false;
                now = q->val;
            }
            pre = q;
            q = q->next;
        }
        if(!dup) {
            p->next = pre;
            p = p->next;
        }
        p->next = NULL;
        return dump.next;
    }
};