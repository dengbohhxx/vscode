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
     * @param head ListNode类 the head
     * @return bool布尔型
     */
    bool isPail(ListNode* head) {
        // write code here
        if(head==NULL||head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<ListNode*> sta;
        while(fast!=NULL&&fast->next!=NULL)
        {
            sta.push(slow);
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL&&fast->next==NULL)
        {
            slow=slow->next;
        }
        while(slow!=NULL)
        {
            if(slow->val!=sta.top()->val)
            {
                return false;
            }
            else
            {
                slow=slow->next;
                sta.pop();
            }
        }
        return true;
    }
};