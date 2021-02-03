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
    void dfs(TreeNode *root,int sum,int target,bool &flag)
    {
        if(root!=NULL)
        {
            sum+=root->val;
            if(root->left==NULL&&root->right==NULL)
            {
                if(sum==target)
                {
                    flag=true;
                }
            }
            dfs(root->left,sum,target,flag);
            dfs(root->right,sum,target,flag);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag=false;
        int sum=0;
        dfs(root,sum,targetSum,flag);
        return flag;
    }
};