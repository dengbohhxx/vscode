/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool issame(TreeNode* r1, TreeNode* r2)
    {
        if(r2==NULL)
            return true;
        if(r1==NULL)
            return false;
        if(r1->val==r2->val)
        {
            return issame(r1->left,r2->left)&&issame(r1->right,r2->right);
        }
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        bool res=false;
        if(pRoot1==NULL||pRoot2==NULL)
            return false;
        else
        {
            if(pRoot1->val == pRoot2->val)
                res=issame(pRoot1,pRoot2);
            if(res==false)
                res=HasSubtree(pRoot1->left,pRoot2);
            if(res==false)
                res=HasSubtree(pRoot1->right,pRoot2);
            return res;
        }
   
    }
};