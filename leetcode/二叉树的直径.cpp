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
    int depth(TreeNode* root,int &ans)
    {
        if(root==NULL)
            return 0;
        else
        {
            int l=depth(root->left,ans);
            int r=depth(root->right,ans);
            ans=max(ans,l+r+1);
            return max(l,r)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=1;//因为[]的时候ans如果为0，返回为0-1=-1.实际应该为1-0=0；
        depth(root,ans);
        return ans-1;
    }
};