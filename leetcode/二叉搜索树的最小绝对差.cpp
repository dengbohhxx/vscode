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
    void midorder(TreeNode * root,vector<int> &str)
    {
        if(root==NULL)
        {
            return;
        }
        midorder(root->left,str);
        str.push_back(root->val);
        midorder(root->right,str);
    }
    int getMinimumDifference(TreeNode* root) {
         if(root==NULL)
        {
            return 0;
        }
        vector<int> str;
        midorder(root,str);
        int min1=INT_MAX;
        int n=str.size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                min1=min(min1,abs(str[i]-str[j]));
            }
        }
        return min1;
    }
};