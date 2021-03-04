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
 class Solution {
public:
    void dfs(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return ;
        else
        {
            dfs(root->left,vec);
            dfs(root->right,vec);
            vec.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        dfs(root,vec);
        return vec;
    }
};
 */
class Solution {
public:
    void last(TreeNode* root,vector<int> &vec)
    {
        stack<TreeNode* > stk1,stk2;
        TreeNode * p;
        stk1.push(root);
        while(!stk1.empty())
        {
            p=stk1.top();
            stk1.pop();
            stk2.push(p);
            if(p->left!=NULL)
                stk1.push(p->left);
            if(p->right!=NULL)
                stk1.push(p->right);
        }
        while(!stk2.empty())
        {
            vec.push_back(stk2.top()->val);
            stk2.pop();
        }

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        if(root==NULL)
            return vec;
        last(root,vec);
        return vec;
    }
};