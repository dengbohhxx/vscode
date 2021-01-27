/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isvalid(TreeNode* root,TreeNode*min,TreeNode*max)
    {
        if(root==NULL)
            return true;
        else if(min!=NULL&&root->val<=min->val)
            return false;
        else if(max!=NULL&&root->val>=max->val)
            return false;
        return isvalid(root->left,min,root)&&isvalid(root->right,root,max);
    }
    bool isValidBST(TreeNode* root) {
        return isvalid(root,NULL,NULL); 
    }
};