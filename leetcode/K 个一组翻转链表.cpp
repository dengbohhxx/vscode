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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        int count=0;
        ListNode * p=head;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        if(count<k)
            return head;
        ListNode * newhead=new ListNode(0);
        ListNode * pre=newhead;
        newhead->next=head;
        p=head;
        ListNode * p1=head->next;
        for(int i=0;i<count/k;i++)
        {
            for(int j=1;j<k;j++)
            {
                p->next=p1->next;
                  p1->next=pre->next;
                pre->next=p1;
                p1=p->next;
            }
            pre=p;
            p=p1;
            if(p1!=NULL)
                p1=p1->next;
        }
        return newhead->next;
    }
};