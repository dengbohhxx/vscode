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
     * @param m int整型 
     * @param n int整型 
     * @return ListNode类
     */
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // write code here
        if(m==n)
            return head;
        if(head==NULL)
            return NULL;
        ListNode * root=new ListNode(-1);//先new一个新的头结点，防止从第一个节点开始逆序，后面接head
        root->next=head;
        ListNode * pre=root;
        ListNode * p=head;
        int k=n-m;
        m=m-1;
        while(m--)
        {
            pre=pre->next;
            p=p->next;
        }
        //头插法
        ListNode * p1=p->next;
        while(k--)
        {
            p->next=p1->next;
            p1->next=pre->next;
            pre->next=p1;
            p1=p->next;
        }
        return root->next;
    }
};