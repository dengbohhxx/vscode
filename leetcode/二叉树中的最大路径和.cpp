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
    int helper(TreeNode *root,int &m)
    {
        if(root==NULL)
            return 0;
        int l=helper(root->left,m);
        int r=helper(root->right,m);
        int cursum=max(root->val,max(root->val+l,root->val+r));
        int curmax=max(cursum,l+r+root->val);
        m=max(m,curmax);
        return cursum;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int m=INT_MIN;
        helper(root,m);
        return m;
    }
};