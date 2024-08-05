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
class Solution {
public:
    ListNode* reverse(ListNode* &node) {
        
        ListNode *prev = nullptr, *next, *curr = node;
        
        while(curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        l1 = reverse(l1);
        l2 = reverse(l2);
        
        ListNode* sumList = nullptr;
        ListNode* head;
        
        int carry = 0, sum = 0;
        
        while(l1 != nullptr || l2 != nullptr) {
            
            sum = (l1 != nullptr) ? l1->val : 0;
            sum += (l2 != nullptr) ? l2->val : 0;
            sum += carry;
            
            carry = sum / 10;
            sum = sum % 10;
            
            l1 = (l1 != nullptr) ? l1->next : l1;
            l2 = (l2 != nullptr) ? l2->next : l2;
            
            if(sumList == nullptr) {
                sumList = new ListNode(sum);
                head = sumList;
            } else {
                sumList->next = new ListNode(sum);
                sumList = sumList->next;
            }
        }
        
        if(carry != 0) {
            sumList->next = new ListNode(carry);
            sumList = sumList->next;
        }
        
        sumList = reverse(head);
        return sumList;
    }
};