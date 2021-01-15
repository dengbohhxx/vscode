/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<root->val&&q->val<root->val)//p,q位于root左子树
            return lowestCommonAncestor(root->left,p,q);
        if(p->val>root->val&&q->val>root->val)//p,q位于root右子树
            return lowestCommonAncestor(root->right,p,q);
        return root;//p,q位于root左由两个子树
    }
};