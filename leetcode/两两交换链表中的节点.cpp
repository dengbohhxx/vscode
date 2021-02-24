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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode * newhead=new ListNode(0);
        newhead->next=head;
        ListNode * temp=newhead;
        while(temp->next!=NULL&&temp->next->next!=NULL)
        {
            ListNode* node1=temp->next;
            ListNode *node2=temp->next->next;
            temp->next=node2;
            node1->next=node2->next;
            node2->next=node1;
            temp=node1;
        }
        return newhead->next;

    }
};
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
        {
            return head;
        }
        ListNode * newhead=head->next;
        head->next=swapPairs(newhead->next);
        newhead->next=head;
        return newhead;
    }
};