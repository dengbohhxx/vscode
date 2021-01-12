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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(l1==NULL&&l2==NULL)
        {
            return NULL; 
        }
        ListNode* head=new ListNode(0);
        ListNode *p=head;
        int flag=0;
        while(l1!=NULL||l2!=NULL||flag!=0)
        {
            int m=0;
            int n=0;
            if(l1!=NULL)
            {
                m=l1->val;
            }
            if(l2!=NULL)
            {
                n=l2->val;
            }
            int temp=m+n+flag;
            p->next=new ListNode(temp%10);
            p=p->next;
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
            flag=temp/10;
        }
        return head->next;
    }
};