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
#include<bits/stdc++.h>
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL|| head->next==NULL)
            return head;
        unordered_set<int> s;
        ListNode* start = head;
        ListNode* prev = NULL;
        while(start){
            if(s.find(start->val)!=s.end()){
                prev->next=start->next;
                start=start->next;
            }
            else{
                s.insert(start->val);
                prev=start;
                start=start->next;
            }
        }
        return head;
    }
};