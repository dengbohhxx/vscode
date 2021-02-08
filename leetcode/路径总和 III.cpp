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
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
        {
            return 0;
        }
        int result=count(root,sum);
        int l=pathSum(root->left,sum);
        int r=pathSum(root->right,sum);
        return result+l+r;

    }
    int count(TreeNode * root,int sum)
    {
        if(root==NULL)
            return 0;
        sum-=root->val;
        int result=sum==0?1:0;
        return result+count(root->left,sum)+count(root->right,sum);
    }
};