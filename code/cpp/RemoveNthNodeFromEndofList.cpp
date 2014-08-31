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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        p->next = head;
        ListNode *h = head;
        while(h && n > 0) {
            n --;
            h = h->next;
        }
        if(n > 0) {
            return head;
        }
        while(h) {
            p = p->next;
            h = h->next;
        }
        p->next = p->next->next;
        return dump.next;
    }
};