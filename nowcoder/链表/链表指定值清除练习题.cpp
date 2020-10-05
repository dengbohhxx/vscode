/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ClearValue {
public:
    ListNode* clear(ListNode* head, int val) {
        // write code here
        ListNode * newhead=new ListNode(0);
        ListNode * p=head;
        ListNode * pnew=newhead;
        while(p!=NULL)
        {
            if(p->val!=val)
            {
                pnew->next=p;
                pnew=pnew->next;
            }
            p=p->next;
        }
        pnew->next=NULL;
        return newhead->next;
    }
};