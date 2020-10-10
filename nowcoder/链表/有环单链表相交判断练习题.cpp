/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
class ChkIntersection {
public:
    //寻找环的起始节点
    ListNode* chkloop(ListNode* head)
    {
        ListNode* fast=head;
        ListNode *slow=head;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast)
                break;
        }
            fast=head;
            while(fast!=slow)
            {
                fast=fast->next;
                slow=slow->next;
            }
            return fast;

 
    }
        //当两个有环链表的起始节点相同时，寻找相交节点
        ListNode * findpoint(ListNode* head1, ListNode* head2,ListNode* node)
        {
            int m=0,n=0;
            ListNode* p1=head1;
            ListNode* p2=head2;
            while(p1!=node)
            {
                m++;
                p1=p1->next;
            }
            while(p2!=node)
            {
                m++;
                p2=p2->next;
            }
            if(m>=n)
            {
                p1=head1;
                p2=head2;
            }
            else
            {
                p1=head2;
                p2=head1;
            }
            int var=m-n;
            while(n--)
            {
                p1=p1->next;
            }
            while(p1!=node&&p2!=node)
            {
                if(p1==p2)
                    return p1;
                p1=p1->next;
                p2=p2->next;
            }
            return node;
        }
        
        //主函数
    bool chkInter(ListNode* head1, ListNode* head2, int adjust0, int adjust1) 
    {
        // write code here
        ListNode* node1=chkloop(head1);
        ListNode* node2=chkloop(head2);
        if(node1==node2)//两个环的起始节点相同
        {
            if(findpoint(head1,head2,node1)!=NULL)
                return findpoint(head1,head2,node1);
        }
            ListNode* p1=node1->next;
            while(p1!=node1)
            {
                if(p1==node2)
                    return p1||node2;
                p1=p1->next;
            }
            return false;
    }
};