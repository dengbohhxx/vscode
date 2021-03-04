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
    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL)
        {
            return NULL;
        }
        ListNode * newhead=new ListNode(0);
        newhead->next=head;
        ListNode * lastsorted=head;
        ListNode * cur=head->next;
        while(cur!=NULL)
        {
            if(lastsorted->val<=cur->val)
            {
                lastsorted=lastsorted->next;
            }
            else
            {
                ListNode * pre=newhead;
                while(pre->next->val<=cur->val)
                {
                    pre=pre->next;
                }
                lastsorted->next=cur->next;
                cur->next=pre->next;
                pre->next=cur;
            }
            cur=lastsorted->next;
        }
        return newhead->next;
    }
};