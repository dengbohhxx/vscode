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
     * @return int整型
     */
    int maxDepth(TreeNode* root) {
        // write code here
        if(root==NULL)
            return 0;
        else
        {
            int lh=maxDepth(root->left);
            int rh=maxDepth(root->right);
            return max(lh,rh)+1;
        }
    }
};