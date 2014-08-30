/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    void together(RandomListNode *head) {
        RandomListNode *p = head;
        while(p) {
            RandomListNode *tmp = new RandomListNode(p->label);
            tmp->next = p->next;
            p->next = tmp;
            p = tmp->next;
        }
    }
    void random(RandomListNode *head) {
        RandomListNode *p = head;
        while(p) {
            RandomListNode *q = p->next;
            if(p->random) {
                q->random = p->random->next;
            }
            p = q->next;
        }
    }
    RandomListNode *cut(RandomListNode *head) {
        RandomListNode dump = RandomListNode(-1);
        RandomListNode *p = head;
        RandomListNode *q = &dump;
        while(p) {
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            p = p->next;
        }
        return dump.next;
    }
    RandomListNode *copyRandomList(RandomListNode *head) {
        together(head);
        random(head);
        return cut(head);
    }
};