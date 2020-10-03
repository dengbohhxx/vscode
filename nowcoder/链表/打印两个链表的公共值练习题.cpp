/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Common {
public:
    vector<int> findCommonParts(ListNode* headA, ListNode* headB) {
        // write code here
        ListNode* p1=headA;
        ListNode* p2=headB;
        vector<int> A;
        //链表为空
        if (p1 == NULL || p2 == NULL)
		{
			return A;
		}
        
        //循环直到有一个链表为空时停止
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->val==p2->val)
            {
                A.push_back(p1->val);
                p1=p1->next;
                p2=p2->next;
                continue;
            }
            if(p1->val<p2->val)
            {
                p1=p1->next;
                continue;
            }
            if(p1->val>p2->val)
            {
                p2=p2->next;
                continue;
            }
        }
        return A;
    }
};