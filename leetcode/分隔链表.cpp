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
    ListNode* partition(ListNode* head, int x) {
            if(head==NULL)
                return NULL;
            ListNode * little=new ListNode(0);
            ListNode * p=little;
            ListNode * big=new ListNode(0);
            ListNode *q=big;
            ListNode * p1=head;
            while(p1!=NULL)
            {
                if(p1->val<x)
                {
                    p->next=new ListNode(p1->val);
                    p=p->next;
                }
                else
                {
                    q->next=new ListNode(p1->val);
                    q=q->next;
                }
                p1=p1->next;
            }
            p->next=big->next;
            return little->next;
    }
};