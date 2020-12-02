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
     * @param sum int整型 
     * @return bool布尔型
     */
    bool hasPathSum(TreeNode* root, int sum) {
        // write code here
        if(root==NULL)
            return false;
        if(root->left==NULL&&root->right==NULL&&sum-root->val==0)
            return true;
        else
            return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);
    }
};