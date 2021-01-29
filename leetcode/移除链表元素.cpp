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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL)
            return head;
        ListNode * head1=new ListNode(0);
        ListNode * p=head1;
        ListNode * q=head;
        while(q!=NULL)
        {
            if(q->val!=val)
            {
                p->next=new ListNode(q->val);
                p=p->next;
            }
            q=q->next;
        }
        return head1->next;
    }
};