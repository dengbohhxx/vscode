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
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        else
        {
            int lh=0;
            int rh=0;
            TreeNode * p=root->left;
            while(p!=NULL)
            {
                p=p->left;
                lh++;
            }
            p=root->right;
            while(p!=NULL)
            {
                p=p->right;
                rh++;
            }
            if(lh==rh)
            {
                return pow(2,rh+1)-1;
            }
            else
            {
                return 1+countNodes(root->left)+countNodes(root->right);
            }
        }
    }
};
 */
class Solution {
public:
    void countnode(TreeNode * root,int &k)
    {
        if(root==NULL)
            return ;
        else
        {
            int lh=0;
            int rh=0;
            TreeNode * p=root->left;
            while(p!=NULL)
            {
                p=p->left;
                lh++;
            }
            p=root->right;
            while(p!=NULL)
            {
                p=p->left;
                rh++;
            }
            if(lh==rh)//左子树肯定是满二叉树
            {
                k=k+1+pow(2,lh)-1;
                countnode(root->right,k);
            }
            else//右子树肯定是满二叉树
            {
                k=k+1+pow(2,rh)-1;
                countnode(root->left,k);
            }
        }
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
        int k=0;
        countnode(root,k);
        return k;
    }
};