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
    ListNode *reverse(ListNode *head) {
        ListNode *pre = NULL;
        ListNode *p = head;
        while(p) {
            ListNode *tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return pre;
    }
    void reorderList(ListNode *head) {
        if(head == NULL || head->next == NULL) {
            return;
        }
        ListNode *p = head;
        ListNode *q = head;
        ListNode *pre = NULL;
        while(p && p->next) {
            pre = q;
            p = p->next->next;
            q = q->next;
        }
        ListNode *r = reverse(q);
        pre->next = NULL;
        p = head;
        ListNode dump = ListNode(-1);
        ListNode *t = &dump;
        while(p && r){
            t->next = p;
            p = p->next;
            t = t->next;
            t->next = r;
            r = r->next;
            t = t->next;
        }
        if(p) {
            t->next = p;
        }
        if(r) {
            t->next = r;
        }
    }
};