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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        p->next = NULL;
        ListNode *q = head;
        if(head == NULL || head->next == NULL) {
            return head;
        }
        while(q != NULL) {
            p = &dump;
            p = p->next;
            ListNode *pre = &dump;
            bool flg = false;
            while(p) {
                if(p->val < q->val) {
                    pre = p;
                    p = p->next;
                } else {
                    flg = true;
                    pre->next = q;
                    q = q->next;
                    pre->next->next = p;
                    break;
                }
            }
            if(!flg) {
                pre->next = q;
                q = q->next;
                pre->next->next = p;
            }
        }
        return dump.next;
    }
};