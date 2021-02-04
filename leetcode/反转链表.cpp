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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode * p=head->next;
        ListNode * newhead=head;
        while(p!=NULL)
        {
            head->next=p->next;
            p->next=newhead;
            newhead=p;
            p=head->next;
        }
        return  newhead;
    }
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode * pre=NULL;
        ListNode * p=NULL;
        while(head!=NULL)
        {
            p=head->next;
            head->next=pre;
            pre=head;
            head=p;
        }
        return pre;
    }
};
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==NULL||head->next==NULL)
            return head;
        ListNode * last=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return last;

    }
};
