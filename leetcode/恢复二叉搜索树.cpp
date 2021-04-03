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
    void midorder(TreeNode * root,vector<int> &vec)
    {
        stack<TreeNode*> stk;
        TreeNode *current=root;
        while(!stk.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                stk.push(current);
                current=current->left;
            }
            else
            {
                current=stk.top();
                vec.push_back(current->val);
                stk.pop();
                current=current->right;
            }
        }
    }
    vector<int> findError(TreeNode* root)
    {
        vector<int> vec;
        vector<int> res(2);
        midorder(root,vec);
        int k=0;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]<vec[i-1])
            {
                k++;
                if(k==1)
                {
                    res[0]=vec[i];
                    res[1]=vec[i-1];
                }
                else if(k==2)
                {
                    res[0]=vec[i];
                }
            }
        }
        return res;
    }
    void recover(TreeNode * root,int x,int y)
    {
        if(root==NULL)
            return;
        if(root->val==x||root->val==y)
        {
            root->val=root->val==x?y:x;
        }
        recover(root->left,x,y);
        recover(root->right,x,y);
    }
    void recoverTree(TreeNode* root) {
        auto res=findError(root);
        recover(root,res[0],res[1]);
    }
};