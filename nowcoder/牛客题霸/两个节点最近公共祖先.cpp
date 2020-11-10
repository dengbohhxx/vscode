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
     * @param o1 int整型 
     * @param o2 int整型 
     * @return int整型
     */
    
    TreeNode* lastorder(TreeNode* root, int o1, int o2)
    {
        if(root==NULL||root->val==o1||root->val==o2)
            return root ;
        else
        {
            TreeNode*ln=lastorder(root->left,o1,o2);
            TreeNode*rn=lastorder(root->right,o1,o2);
            if(ln!=NULL&&rn!=NULL)
                return root;
            if(ln==NULL)
                return rn;
            if(rn==NULL)
                return ln;
        }
    }
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        // write code here
          TreeNode* node=lastorder(root,o1,o2);
          return node->val;
          
    }
};