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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        else
        {
            if(head->val==head->next->val)
            {
                ListNode *p=head->next;
                while(p!=NULL&&p->val==head->val)
                {
                    p=p->next;
                }
                return deleteDuplicates(p);

            }
            else
            {
                head->next=deleteDuplicates(head->next);
                return head;
            }
        }
    }
};