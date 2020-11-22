/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
/*
class Solution {
public:
    void merge(ListNode* pHead1, ListNode* pHead2,ListNode *&head)
    {
        if(pHead1==NULL&&pHead2==NULL)
            return;
        else if(pHead1==NULL&&pHead2!=NULL)
        {
            head->next=pHead2;
            return;
        }
        else if(pHead1!=NULL&&pHead2==NULL)
        {
            head->next=pHead1;
            return;
        }
        else
        {
            if(pHead1->val<=pHead2->val)
            {
                head->next=pHead1;
                head=head->next;
                merge(pHead1->next,pHead2,head);
            }
            else
            {
                head->next=pHead2;
                head=head->next;
                merge(pHead1,pHead2->next,head);
            }
        }
        
    }
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL&&pHead2==NULL)
            return NULL;
        else if(pHead1==NULL&&pHead2!=NULL)
            return pHead2;
        else if(pHead1!=NULL&&pHead2==NULL)
            return pHead1;
        ListNode * head=new ListNode(0);
        ListNode * p=head;
        merge(pHead1,pHead2,p);
        return head->next;
    }
};
*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        else if(pHead2==NULL)
            return pHead1;
        ListNode* head=NULL;
        if(pHead1->val<=pHead2->val)
        {
                head=pHead1;
                head->next=Merge(pHead1->next,pHead2);
        }
        else
        {
                head=pHead2;
                head->next=Merge(pHead1,pHead2->next);
        }
        return head;
    }
};