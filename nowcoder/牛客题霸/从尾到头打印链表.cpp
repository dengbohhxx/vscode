/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    void reverselist(ListNode* head,vector<int> &vec)
    {
        if(head==NULL)
            return;
        else
        {
            reverselist(head->next,vec);
            vec.push_back(head->val);
        }
    }
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> vec;
        if(head==NULL)
            return vec;
        reverselist(head,vec);
        return vec;
    }
};