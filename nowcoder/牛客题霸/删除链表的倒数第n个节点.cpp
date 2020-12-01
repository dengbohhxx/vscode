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
     * @param head ListNode类 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        if(head==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(n--)
        {
            fast=fast->next;
        }
        ListNode* pre=NULL;
        if(fast==NULL)
        {
            return slow->next;
        }
        while(fast!=NULL)
        {
            pre=slow;
            fast=fast->next;
            slow=slow->next;
        }
        pre->next=slow->next;
        slow->next=NULL;
        return head;
    }
};