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
     * @return ListNode类
     */
    ListNode* deleteDuplicates(ListNode* head) {
        // write code here
        if(head==NULL||head->next==NULL)
                return head;
        if(head->val==head->next->val)
        {
            return deleteDuplicates(head->next);
        }
        else
        {
            head->next=deleteDuplicates(head->next);
            return head;
        }
    }
};