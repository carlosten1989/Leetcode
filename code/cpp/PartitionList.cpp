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
    ListNode *partition(ListNode *head, int x) {
        
        ListNode dumpl = ListNode(-1);
        ListNode dumpr = ListNode(-1);
        ListNode *l = &dumpl;
        ListNode *r = &dumpr;
        ListNode *p = head;
        while(p) {
            if(p->val < x) {
                l->next = p;
                l = l->next;
            } else {
                r->next = p;
                r = r->next;
            }
            p = p->next;
        }
        r->next = NULL;
        l->next = dumpr.next;
        return dumpl.next;
    }
};