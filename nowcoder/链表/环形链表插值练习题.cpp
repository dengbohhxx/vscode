/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class InsertValue {
public:
    ListNode* insert(vector<int> A, vector<int> nxt, int val) {
        // write code here
        ListNode * now=new ListNode(val);
        if(A.size()==0)
        {
            return now;
        }
        //重建环形链表
        ListNode * head =new ListNode(A[0]);
        ListNode * p=head;
        for(int i=1;i<A.size();i++)
        {
            ListNode * q=new ListNode(A[i]);
            p->next=q;
            p=p->next;
        }
        p->next=head;
        //插入值小于所有有序环形链表值的情况
        if(val<head->val)
        {
            p=head;
            while(p->next!=head)
                p=p->next;
            now->next=head;
            head=now;
            p->next=NULL;
            return head;
        }
        //遍历链表
        p=head;
        while(p->next->val<val)//p的next节点的值小于val
        {
            if(p->next==head)//当插入值大于有序环形链表尾值时
            {
                p->next=now;
                now->next=NULL;
                return head;
            }
            p=p->next;
        }
        
        
        //在链表中间插入，此时p指针已经循环到对应位置
        now->next=p->next;
        p->next=now;
        p=head;
        while(p->next!=head)
            p=p->next;
        p->next=NULL;
        return head;
        
        
        
    }
};