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
    unordered_map<TreeNode * ,int> f,g;
    void dfs(TreeNode * node)
    {
        if(node==NULL)
            return;
        else
        {
            dfs(node->left);
            dfs(node->right);
            f[node]=node->val+g[node->left]+g[node->right];
            g[node]=max(f[node->left],g[node->left])+max(f[node->right],g[node->right]);
        }
    }
    int rob(TreeNode* root) {
        dfs(root);
        return max(f[root],g[root]);
    }
};