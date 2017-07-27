/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

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
        int carry = 0;
        int val = 0;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while (nullptr != l1 || nullptr != l2 || 0 != carry) {
            val = 0;
            if (nullptr != l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (nullptr != l2) {
                val += l2->val;
                l2 = l2->next;
            }
            val += carry;
            carry = val / 10;
            val   = val % 10;
            temp->next = new ListNode(val);
            temp = temp->next;
        }
        temp = result->next;
        delete result;
        return temp;
    }
};