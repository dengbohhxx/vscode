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
     * @param root1 TreeNode类 
     * @param root2 TreeNode类 
     * @return bool布尔型
     */
    bool isContains(TreeNode* root1, TreeNode* root2) {
        // write code here
        if(root1==NULL&&root2==NULL)
            return true;
        else if(root1!=NULL&&root2==NULL)
            return false;
        else if(root1==NULL&&root2!=NULL)
            return false;
        else
        {
            if(root1->val==root2->val)
                return isContains(root1->left, root2->left)&&isContains(root1->right, root2->right);
            else
            {
                return isContains(root1->left,root2)||isContains(root1->right,root2);
            }
        }
        
    }
};