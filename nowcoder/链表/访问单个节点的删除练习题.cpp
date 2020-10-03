/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class Remove {
public:
    ListNode* removeNode(ListNode* pHead, int delVal) {
        // write code here
        //链表为空
        if(pHead==NULL)
            return pHead;
        //删除的节点为头结点
        if(pHead->val==delVal)
        {
            //ListNode * node=new ListNode(delVal);
           // node=pHead->next;
           // pHead=node;
            pHead=pHead->next;//直接将头结点设为Phead的下一个
            return pHead;
        }
        //设置pre和cur
        ListNode* pre=pHead;
        ListNode* cur=pre->next;
        while(cur!=NULL)//当cur不为NULL，循环
        {
            if(cur->val==delVal)
            {
                pre->next=cur->next;
                cur->next=NULL;//将CUR的next设为空 ，从链表中断出来
                break;
            }
            pre=cur;
            cur=cur->next;
        }
        return pHead;
    }
};