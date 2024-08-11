class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return head;
        Node *tmp = head;
        unordered_map<Node*, Node*>mp;
        while(tmp) {
            Node *newnode = new Node(tmp->val);
            mp[tmp] = newnode;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp){
            mp[tmp]->random = mp[tmp->random];
            mp[tmp]->next = mp[tmp->next];
            tmp = tmp->next;
        }
        return mp[head];
        
    }
};