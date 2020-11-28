/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
          if(pHead==NULL||pHead->next==NULL)// 只有0个或1个节点
             return pHead;
          if(pHead->val==pHead->next->val)// 当前节点是重复节点
          {
              ListNode* node=pHead;
              while(node!=NULL&&node->val==pHead->val)// 跳过值与当前节点相同的全部节点，找到第一个与当前节点不同的节点
                  node=node->next;
              return deleteDuplication(node);// 从第一个与当前结点不同的结点继续递归
          }
          else
          {
              pHead->next=deleteDuplication(pHead->next);// 保留当前节点，从下一个节点继续递归
              return pHead;
          }
        
    }
};