class Solution {
public:
    void reverse(ListNode* hold, ListNode* &end) {
        ListNode* curr = hold->next, *next, *first = hold, *last = curr;
        while(curr!=end) {
            next = curr->next;
            curr->next = hold;
            hold = curr;
            curr = next;
        }
         first->next = hold;
         last->next = end;
        // hold->next = last;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // for(int i = 1;i<left)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        // head = dummy;
        ListNode* prev = dummy, *end = head;
        int i = 1;
        while(i<left) {
            prev = prev->next;
            i++;
        }
        ListNode *hold = prev;
        prev = prev->next;
        while(i<=right) {
            prev = prev->next;
            i++;
        }
        reverse(hold,prev);
        
        
        
        
        return dummy->next;
        
    }
};