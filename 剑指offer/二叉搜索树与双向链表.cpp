/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    void conv(TreeNode* head,TreeNode *&plast)
    {
        if(head==NULL)
            return;
        if(head->left!=NULL)
            conv(head->left,plast);
        head->left=plast;
        if(plast!=NULL)
            plast->right=head;
        plast=head;
        if(head->right!=NULL)
            conv(head->right,plast);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==NULL)
            return NULL;
        TreeNode* plast=NULL;
        conv(pRootOfTree,plast);
        TreeNode* phead=plast;
        while( phead->left!=NULL)
            phead=phead->left;
        return phead;
    }
};
*/
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        stack<TreeNode*> store;
        TreeNode* current=pRootOfTree;
        TreeNode* pre=NULL;
        while(!store.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                store.push(current);
                current=current->left;
            }
            else
            {
                current=store.top();
                if(pre==NULL)//当为双向链表的头结点
                {
                    pRootOfTree=current;
                    pre=current;
                }
                else
                {
                    pre->right=current;//可以把right理解为双向链表的next指
                    current->left=pre;//left理解为双向链表的pre指
                    pre=current;
                }
                store.pop();
                current=current->right;
            }
        }
        return pRootOfTree;
    }
};