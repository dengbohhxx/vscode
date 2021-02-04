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
    void dfs(TreeNode * root,string s,int &sum)
    {
        if(root!=NULL)
        {
            s+=to_string(root->val);

            if(root->left==NULL&&root->right==NULL)
            {
                sum+=stoi(s);
            }
            dfs(root->left,s,sum);
            dfs(root->right,s,sum);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        string s;
        int sum=0;
        dfs(root,s,sum);
        return sum;
    }
};