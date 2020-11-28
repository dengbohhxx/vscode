/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        else
            return issym(pRoot->left,pRoot->right);
    }
    bool issym(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        else if((left!=NULL&&right==NULL)||(left==NULL&&right!=NULL))
            return false;
        else
        {
            if(left->val==right->val)
                return issym(left->left,right->right)&&issym(left->right,right->left);
            else
                return false;
        }
    }

};