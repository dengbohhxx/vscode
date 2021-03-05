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
    void preorder(TreeNode* root,vector<TreeNode*> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            vec.push_back(root);
            preorder(root->left,vec);
            preorder(root->right,vec);
        }
    }
    void flatten(TreeNode* root) {
        vector<TreeNode *> vec;
        preorder(root,vec);
        int n=vec.size();
        for(int i=1;i<n;i++)
        {
            vec[i-1]->left=NULL;
            vec[i-1]->right=vec[i];
        }

    }
};