/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL||pHead->next==NULL)
            return NULL;
        ListNode* fast=pHead;
        ListNode* slow=pHead;
        while(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            {
                break;
            }
        }
        if(fast==slow)
        {
            fast=pHead;
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return fast;
        }
        return NULL;
    }
};