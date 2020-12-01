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
     * @param l1 ListNode类 
     * @param l2 ListNode类 
     * @return ListNode类
     */
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // write code here
        if(l1==NULL&&l2==NULL)
            return NULL;
        else if(l1==NULL&&l2!=NULL)
            return l2;
        else if(l1!=NULL&&l2==NULL)
            return l1;
        ListNode* head=NULL;
        if(l1->val<=l2->val)
        {
            head=new ListNode(l1->val);
            head->next=mergeTwoLists(l1->next,l2);
        }
        else
        {
            head=new ListNode(l2->val);
            head->next=mergeTwoLists(l1,l2->next);
        }
        return head;
    }
};