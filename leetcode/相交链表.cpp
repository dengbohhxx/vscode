/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL)
            return NULL;
        int len1=0;
        ListNode * p=headA;
        while(p!=NULL)
        {
            p=p->next;
            len1++;
        }
        int len2=0;
        ListNode * q=headB;
        while(q!=NULL)
        {
            q=q->next;
            len2++;
        }
        if(len1>len2)
        {
            p=headA;
            q=headB;
        }
        else
        {
            swap(len1,len2);
            p=headB;
            q=headA;
        }
        for(int i=0;i<len1-len2;i++)
        {
            p=p->next;
        }
        while(p!=NULL&&q!=NULL)
        {
            if(p==q)
                return p;
            p=p->next;
            q=q->next;
        }
        return NULL;
    }
};