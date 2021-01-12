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
    void midorder(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            midorder(root->left,vec);
            vec.push_back(root->val);
            midorder(root->right,vec);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        midorder(root,vec);
        return vec[k-1];
    }
}; 
 */
class Solution {
public:
    void midorder(TreeNode* root,int &idx,int k,TreeNode *&node)//传指针的引用！！！
    {
        if(root==NULL)
            return;
        midorder(root->left,idx,k,node);
        idx++;
        if(idx==k)
            {
            node=root;
            return;
            }
        midorder(root->right,idx,k,node);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL||k==0)
            return NULL;
        TreeNode * node=NULL;
        int idx=0;
        midorder(root,idx,k,node);
        return node->val;
    }
};
