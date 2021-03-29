/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        Node * p=head;;
        while(p!=NULL)
        {
            Node * temp=new Node(p->val);
            temp->next=p->next;
            p->next=temp;
            p=temp->next;
        }
        p=head;
        while(p!=NULL)
        {
            Node * temp=p->next;
            if(p->random!=NULL)
                temp->random=p->random->next;
            p=temp->next;
        }
        p=head;
        Node *newhead=head->next;
        while(p->next!=NULL)
        {
            Node* temp=p->next;
            p->next=temp->next;
            p=temp;
        }
        return newhead;
    }
};