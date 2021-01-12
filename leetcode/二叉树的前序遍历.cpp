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
    vector<int> preorderTraversal(TreeNode* root) {
     
        
        stack<TreeNode*> stk;
        vector<int> vec;
        if(root==NULL)
            return vec;
        stk.push(root);
        while(!stk.empty())
        {
            TreeNode * current=stk.top();
            vec.push_back(current->val);
            stk.pop();
            if(current->right!=NULL)
            {
                stk.push(current->right);
            }
            if(current->left!=NULL)
            {
                stk.push(current->left);

            }
        }
        return vec;
    }
};