/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkLoop {
public:
    int chkLoop(ListNode* head, int adjust) {
        // write code here
        if(head==NULL)//如果为空直接返回
            return -1;
        ListNode * fast=head;
        ListNode * slow=head;
        while(fast!=NULL&&fast->next!=NULL)//当链表长度为奇数和偶数的不同情况
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)//这个判断一定要在重新设定快慢两个指针的后面，否则在第一个节点时即跳出循环
               break;
        }
        if(fast==NULL||fast->next==NULL)
        {
            return -1;
        }
        else
        {
            fast=head;
            while(slow!=fast)
           {
               slow=slow->next;
               fast=fast->next;
           }
           return fast->val;
        }
    }
};