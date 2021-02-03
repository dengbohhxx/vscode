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
    void dfs(TreeNode * root,vector<int> row,vector<vector<int> > &res,int sum,int target)
    {
        if(root!=NULL)
        {
            row.push_back(root->val);
            sum+=root->val;
            if(root->left==NULL&&root->right==NULL&&sum==target)
            {
                res.push_back(row);
            }
            dfs(root->left,row,res,sum,target);
            dfs(root->right,row,res,sum,target);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
            vector<vector<int>> res;
            vector<int> row;
            if(root==NULL)
               return res;
            int sum=0;
            dfs(root,row,res,sum,targetSum);
            return res;
    }
};