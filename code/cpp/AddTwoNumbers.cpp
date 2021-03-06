/**You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dump = ListNode(-1);
        ListNode *p = &dump;
        int carry = 0;
        while(l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum >= 10 ? sum - 10 : sum;
            ListNode *tmp = new ListNode(sum);
            p->next = tmp;
            p = p->next;
            l2 = l2->next;
        }
        if(carry == 1) {
            ListNode *tmp = new ListNode(1);
            p->next = tmp;
            p = p->next;
        }
        p->next = NULL;
        return dump.next;
    }
};