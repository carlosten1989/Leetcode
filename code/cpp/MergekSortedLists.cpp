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
    ListNode *merge(ListNode *p, ListNode *q) {
        ListNode dump = ListNode(-1);
        ListNode *h = &dump;
        while(p && q) {
            if(p->val < q->val) {
                h->next = p;
                p = p->next;
            } else {
                h->next = q;
                q = q->next;
            }
            h = h->next;
        }
        h->next = p ? p : q;
        return dump.next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int size = lists.size();
        if(size == 0) {
            return NULL;
        }
        if(size == 1) {
            return lists[0];
        }
        int i = 0;
        while(i < lists.size()) {
            int size = lists.size();
            ListNode* l1 = lists[i++];
            ListNode* l2 = lists[i++];
            if(i == size) {
                return merge(l1,l2);
            }
            lists.push_back(merge(l1,l2));
        }
    }
};