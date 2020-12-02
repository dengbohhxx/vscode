/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {
        // write code here
        if(head==NULL) return nullptr;
        vector<int> vec;
        ListNode * p=head;
        while(p!=NULL){
            vec.push_back(p->val);
            p=p->next;
        }
        sort(vec.begin(),vec.end());
        p=head;
        int k=0;
        while(p!=NULL){
            p->val=vec[k];
            k++;p=p->next;
        }
        return head;
    }
};