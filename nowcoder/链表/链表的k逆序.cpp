/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class KInverse {
public:
    ListNode* inverse(ListNode* head, int k) {
        // write code here
        //为空立刻返回
        if(head==NULL)
            return head;
        ListNode * p=head;
        int count=0;
        //统计链表大小
        while(p!=NULL)
        {
            count++;
            p=p->next;
        }
        //如果链表长度小于K，直接返回head
        if(count<k)
            return head;
        //初始化头结点为0，头结点下一个节点为head，设定pre，cur，temp，头插法
            /*ListNode *node=new ListNode(0);
            ListNode * pre=node;
            node->next=head;
            ListNode * cur=head;
            ListNode * temp=head->next;
            for(int i=0;i<count/k;i++)
            {
                for(int j=1;j<k;j++)
                {
                cur->next=temp->next;
                temp->next=pre->next;
                pre->next=temp;
                temp=cur->next;
                }
                pre=cur;
            cur=cur->next;
            temp=cur->next;
            }
        return node->next;*/
        ListNode *newhead=new ListNode(0);
        ListNode * pre=newhead;
        newhead->next=head;
        p=head;
        ListNode * p1=head->next;
        for(int i=0;i<count/k;i++)
        {
            for(int j=1;j<k;j++)
            {
                p->next=p1->next;
                p1->next=pre->next;
                pre->next=p1;
                p1=p->next;
            }
            pre=p;
            p=p1;
            p1=p1->next;
        }
        return newhead->next;
    }
};