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
    ListNode * reverselist(ListNode * head)
    {
        if(head==NULL)
            return head;
        ListNode * p=head->next;
        ListNode * newhead=head;
        while(p!=NULL)
        {
            head->next=p->next;
            p->next=newhead;
            newhead=p;
            p=head->next;
        }
        return newhead;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * head1=reverselist(l1);
        ListNode * head2=reverselist(l2);
        ListNode * p1=head1;
        ListNode * p2=head2;
        ListNode * head=new ListNode(0);
        ListNode * p=head;
        int flag=0;
        while(p1!=NULL||p2!=NULL||flag!=0)
        {
            int temp1=0;
            int temp2=0;
            if(p1!=NULL)
            {
                temp1=p1->val;
            }
            if(p2!=NULL)
            {
                temp2=p2->val;
            }
            int temp=temp1+temp2;
            p->next=new ListNode((temp+flag)%10);
            flag=(temp+flag)/10;
            if(p1!=NULL)
            {
                p1=p1->next;
            }
            if(p2!=NULL)
            {
                p2=p2->next;
            }
            p=p->next;

        }
        ListNode * node= reverselist(head->next);
        return node;
    }
};