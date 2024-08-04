class Solution {
  public:
    Node* divide(Node* head) {
        // code here
         Node* newnode=new Node(-1);
        Node* res=newnode;
        Node* temp=head;
        
        while(temp!=NULL)
        {
            if(temp->data%2==0)
            {
                res->next=new Node(temp->data);
                res=res->next;
            }
            temp=temp->next;
        }
        temp=head;
         while(temp!=NULL)
        {
            if(temp->data%2!=0)
            {
                res->next=new Node(temp->data);
                res=res->next;
            }
            temp=temp->next;
        }
        return newnode->next;
    }
};