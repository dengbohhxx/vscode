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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return head;
        int n=1;
        ListNode * p=head;
        while(p->next!=NULL)
        {
            p=p->next;
            n++;
        }
        p->next=head;
        k=k%n;
        ListNode * newhead=head;
        int m=n-k;
        while(m--)
        {
            newhead=newhead->next;
        }
        p=newhead;
        n=n-1;
        while(n--)
        {
            p=p->next;
        }
        p->next=NULL;
        return newhead;
    }
};