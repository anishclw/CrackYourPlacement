/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *sumList = nullptr, *tmp = nullptr;
        int carry = 0;
        while (l1 || l2)
        {
            int val1 = (l1 == nullptr) ? 0 : l1->val;
            int val2 = (l2 == nullptr) ? 0 : l2->val;
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            if (!sumList)
            {
                sumList = new ListNode();
                sumList->val = sum;
                tmp = sumList;
            }
            else
            {
                tmp->next = new ListNode();
                tmp = tmp->next;
                tmp->val = sum;
            }
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        if (carry)
        {
            tmp->next = new ListNode();
            tmp = tmp->next;
            tmp->val = carry;
        }
        return sumList;
    }
};