class Solution {
public:
    /**
     * 
     * @param t1 TreeNode类 
     * @param t2 TreeNode类 
     * @return TreeNode类
     */
    TreeNode* merge(TreeNode* t1, TreeNode* t2)
    {
        if(t1==NULL&&t2==NULL)
            return NULL;
        else if(t1!=NULL&&t2==NULL)
        {
            return t1;
        }
        else if(!t1&&t2)
        {
            return t2;
        }
        else 
        {
            t1->val=t1->val+t2->val;
            t1->left=merge(t1->left,t2->left);
            t1->right=merge(t1->right,t2->right);
            return t1;
        }
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // write code here
        TreeNode *head=merge(t1,t2);
        return head;
    }
};