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
    void reorderList(ListNode *head) {
        ListNode *slow=head;
        ListNode * fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * pre=NULL;
        ListNode * cur=NULL;
        ListNode * q=slow;
        while(q!=NULL)
        {
            cur=q->next;
            q->next=pre;
            pre=q;
            q=cur;
        }
        ListNode *p1=head;
        ListNode *q1=pre;
        while(q1!=slow)
        {
            ListNode * pcur=p1->next;
            ListNode * qcur=q1->next;
            p1->next=q1;
            q1->next=pcur;
            p1=pcur;
            q1=qcur;
        }
    }
};