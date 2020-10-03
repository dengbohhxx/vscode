/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Divide {
public:
    ListNode* listDivide(ListNode* head, int val) {
        // write code here
        ListNode* small=new ListNode(0);
        ListNode* large=new ListNode(0);
        ListNode* psmall=small;
        ListNode* plarge=large;
        ListNode* p=head;
        while(p!=NULL)
        {
            if(p->val<=val)
            {
                psmall->next=p;
                psmall=psmall->next;
            }
            else
            {
                plarge->next=p;
                plarge=plarge->next;
            }
            p=p->next;
        }
        psmall->next=large->next;
        plarge->next=NULL;
        return small->next;
    }
};