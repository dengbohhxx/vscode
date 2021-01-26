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
    bool judge(TreeNode* root,int val)
    {
        if(root==NULL)
            return true;
        else if(root->val!=val)
            return false;
        return judge(root->left,val)&&judge(root->right,val);
    }
    bool isUnivalTree(TreeNode* root) {
        return judge(root,root->val);
    }
};