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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;

        int carry = 0;
        while (l1 || l2 || carry) {
            int n1 = 0;
            if (l1) {
                n1 = l1->val;
                l1 = l1->next;
            }
            int n2 = 0;
            if (l2) {
                n2 = l2->val;
                l2 = l2->next;
            }
            int sum = n1 + n2 + carry;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            carry = sum / 10;
        }

        return dummy.next;
    }
};