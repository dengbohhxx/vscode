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
     * @param x int整型 
     * @return ListNode类
     */
    ListNode* partition(ListNode* head, int x) {
        // write code here
        if(head==NULL)
            return NULL;
        ListNode* little=new ListNode(0);
        ListNode* big=new ListNode(0);
        ListNode* p=little;
        ListNode* q=big;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            if(temp->val<x)
            {
                p->next=new ListNode(temp->val);
                p=p->next;
            }
            else
            {
                q->next=new ListNode(temp->val);
                q=q->next;
            }
            temp=temp->next;
        }
        p->next=big->next;
        return little->next;
    }
};