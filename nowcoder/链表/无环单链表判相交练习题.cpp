/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/

class CheckIntersect {
public:

    void swap(int &a,int &b)
     {
          int temp=a;
          a=b;
          a=temp;
     }

    bool chkIntersect(ListNode* headA, ListNode* headB)
    {
        // write code here
        int m=0;
        int n=0;
        int abs=0;
        ListNode * p1= headA;
        ListNode * p2= headB;
        //计算两链表长度
        while(p1!=NULL)
        {
            m++;
            p1=p1->next;
        }
        while(p2!=NULL)
        {
            n++;
            p2=p2->next;
        }
        if(m<n)
        {
            swap(m,n);
            p1=headB;
            p2=headA;
        }
        else
        {
            p1=headA;
            p2=headB;
        }
        //长的链表先向前走m-n长度
        for(int i=0;i<m-n;i++)
        {
            p1=p1->next;
        }
        while(p1!=NULL&&p2!=NULL)
        {
            if(p1==p2)//注意是判断两个节点是否相等，而不是节点值是否相等
            {
                return true;
            }
            p1=p1->next;
            p2=p2->next;
        }
        return false;
        
    }
};