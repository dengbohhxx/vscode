/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
         if(pHead==NULL)
             return NULL;
         ListNode* p=pHead->next;
         ListNode* newhead=pHead;
         while(p!=NULL)
         {
             pHead->next=p->next;
             p->next=newhead;
             newhead=p;
             p=pHead->next;
         }
        return newhead;
    }
};
*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead==NULL)
             return pHead;
         ListNode* pre=NULL;
         ListNode* p=NULL;
         while(pHead!=NULL)
         {
             p=pHead->next;
             pHead->next=pre;
             pre=pHead;
             pHead=p;
         }
        return pre;
    }
};