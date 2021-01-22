/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void adjust(vector<ListNode*>& heap,int len,int index)
    {
        int minidx=index;
        while(index<len)
        {
            int left=2*index+1;
            int right=2*index+2;
            if(left<len&&heap[left]->val<heap[minidx]->val)
                minidx=left;
            if(right<len&&heap[right]->val<heap[minidx]->val)
                minidx=right;
            if(minidx!=index)
            {
                swap(heap[index],heap[minidx]);
                index=minidx;
            }
            else
            {
                break;
            }    
        }    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return NULL;
        vector<ListNode*> heap;
        for(vector<ListNode*>::iterator iter=lists.begin();iter!=lists.end();iter++)
        {
            if(*iter!=NULL)
            {
                heap.push_back(*iter);
            }
        }
        int len=heap.size();
        for(int i=len/2-1;i>=0;i--)
            adjust(heap,len,i);
        ListNode * head=new ListNode(0);
        ListNode * p=head;
        while(heap.size()>0)
        {
            p->next=new ListNode(heap[0]->val);
            p=p->next;
            heap[0]=heap[0]->next;
            if(heap[0]==NULL)
            {
                swap(heap[0],heap.back());
                heap.pop_back();
            }
            if(heap[0]!=NULL)
            {
                int len1=heap.size();
                adjust(heap,len1,0);
            }
        }
        return head->next;
    }
};