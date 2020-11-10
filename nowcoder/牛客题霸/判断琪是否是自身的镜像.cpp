/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool sym(TreeNode* left,TreeNode* right)
    {
        if(left==NULL&&right==NULL)
            return true;
        else if((left!=NULL&&right==NULL)||(left==NULL&&right!=NULL))
            return false;
        else
        {
            if(left->val==right->val)
                return sym(left->left,right->right)&&sym(left->right,right->left);
            else
                return false;
        }
    }
    bool isSymmetric(TreeNode* root) {
        // write code here
        if(root==NULL)
            return true;
        else
            return sym(root->left,root->right);
    }
};