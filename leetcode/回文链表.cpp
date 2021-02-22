/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 class Solution {
public:
    bool isPalindrome(ListNode* head) {//1.快慢指针 链表逆序
        if(head==NULL)
            return true;
        ListNode * slow=head;
        ListNode *fast=head;
        while(fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode * pre=slow;
        slow=slow->next;
        pre->next=NULL;
        while(slow!=NULL)
        {
            ListNode *temp=slow->next;
            slow->next=pre;
            pre=slow;
            slow=temp;
        }
        ListNode * left=head;
        ListNode * right=pre;
        while(right!=NULL)
        {
            if(left->val==right->val)
            {
                left=left->next;
                right=right->next;
            }
            else
            {
                return false;
            }
        }
        return true;

    }
    2.将链表压入栈，然后倒出时对比
    3.快慢指针，前半部分压入，然后倒出对比
};
 */
class Solution {
public:
//递归
    bool traverse(ListNode * right,ListNode *&left)
    {
        if(right==NULL)
            return true;
        bool res=traverse(right->next,left);
        res=res&&(right->val==left->val);
        left=left->next;
        return res;
    }
    bool isPalindrome(ListNode* head) {
        
        ListNode * left=head;
        return traverse(head,left);
    }
private:
    ListNode * left;
};