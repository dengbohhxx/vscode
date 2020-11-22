class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==NULL||k==0)
            return NULL;
        ListNode* fast=pListHead;
        ListNode* slow=pListHead;
        for(int i=0;i<k-1;i++)
        {
            if(fast->next!=NULL)
                fast=fast->next;
            else
                return NULL;
        }
        while(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};