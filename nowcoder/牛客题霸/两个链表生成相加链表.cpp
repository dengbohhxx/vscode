/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head1 ListNode类 
     * @param head2 ListNode类 
     * @return ListNode类
     */
    ListNode* reverse(ListNode* head)
    {
        ListNode* newhead=head;
        ListNode* p=head->next;
        while(p!=NULL)
        {
            head->next=p->next;
            p->next=newhead;
            newhead=p;
            p=head->next;
        }
        return newhead;
    }
    ListNode* listsum(ListNode*p1,ListNode*p2)
    {
        ListNode* newhead=new ListNode(0);
        ListNode* p=newhead;
        int flag=0;
        while(p1!=NULL||p2!=NULL||flag!=0)
        {
            int a=0;
            int b=0;
            int temp=0;
            if(p1!=NULL)
                a=p1->val;
            if(p2!=NULL)
                b=p2->val;
            temp=a+b+flag;
            p->next=new ListNode(temp%10);
            p=p->next;
            flag=temp/10;
            if(p1!=NULL)
                p1=p1->next;
            if(p2!=NULL)
                p2=p2->next;
        }
        return newhead->next;
    }
    ListNode* addInList(ListNode* head1, ListNode* head2) {
        // write code here
        if(head1==NULL&&head2==NULL)
            return NULL;
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        ListNode*p1=reverse(head1);
        ListNode*p2=reverse(head2);
        ListNode* sumlist=listsum(p1,p2);
        return reverse(sumlist);
    }
};