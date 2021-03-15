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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)
            return head;
        ListNode * odd=head;
        ListNode *even=head->next;
        ListNode * p=even->next;
        while(even!=NULL&&odd!=NULL&&p!=NULL)
        {
            even->next=p->next;
            p->next=odd->next;
            odd->next=p;
            odd=odd->next;
            even=even->next;
            if(even!=NULL)
                p=even->next;
        }
        return head;
    }
};