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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head==NULL)
            return NULL;
        ListNode* head1=new ListNode(0);
        head1->next=head;
        ListNode* pre=head1;
        ListNode * q=head;
        int k1=m-1;
        while(k1--)
        {
            pre=pre->next;
            q=q->next;
        }
        ListNode *newhead=q;
        ListNode *p=q->next;
        int k=n-m;
        while(k--)
        {
            q->next=p->next;
            p->next=newhead;
            newhead=p;
            pre->next=newhead;
            p=q->next;
        }
        return head1->next;
    }
};