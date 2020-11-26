/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL||pHead2==NULL)
            return NULL;
        int p1len=0;
        int p2len=0;
        ListNode* p1= pHead1;
        ListNode* p2= pHead2;
        while(p1!=NULL)
        {
            p1len++;
            p1=p1->next;
        }
        while(p2!=NULL)
        {
            p2len++;
            p2=p2->next;
        }
        if(p1len>=p2len)
        {
            p1= pHead1;
            p2= pHead2;
        }
        else
        {
            p1= pHead2;
            p2= pHead1;
        }
        int m=abs(p1len-p2len);
        for(int i=0;i<m;i++)
        {
            p1=p1->next;
        }
        while(p1&&p2)
        {
            if(p1==p2)
            {
                return p1;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return NULL;
    }
};