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
    vector<TreeNode*> generateTrees(int start, int end)
    {
        if(start>end)
            return{NULL};
        vector<TreeNode*> vec;
        for(int i=start;i<=end;i++)
        {
            vector<TreeNode*> lefttrees=generateTrees(start,i-1);
            vector<TreeNode*> righttrees=generateTrees(i+1,end);
            for(int k=0;k<lefttrees.size();k++)
            {
                for(int j=0;j<righttrees.size();j++)
                {
                    TreeNode * cur=new TreeNode(i);
                    cur->left=lefttrees[k];
                    cur->right=righttrees[j];
                    vec.push_back(cur);
                }
            }
        }
        return vec;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return generateTrees(1,n);
    }
};