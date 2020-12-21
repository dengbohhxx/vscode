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
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* reverseKGroup(ListNode* head, int k) {
        // write code here
        if(head==NULL)
            return head;
        ListNode* p=head;
        int count=0;
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        if(count<k)
            return head;
        ListNode* root=new ListNode(0);
        root->next=head;
        ListNode* pre=root;
        p=head;
        ListNode* p1=head->next;
        for(int i=0;i<count/k;i++)
        {
            for(int j=0;j<k-1;j++)
            {
                p->next=p1->next;
                p1->next=pre->next;
                pre->next=p1;
                p1=p->next;
            }
            pre=p;
            p=p1;
            p1=p->next;
        }
        return root->next;
    }
};