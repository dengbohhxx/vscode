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
    int find(vector<int>  nums,int maxnum)
    {
        int i=0;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==maxnum)
                break;
        }
        return i;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        else
        {
            int maxnum=*max_element(nums.begin(),nums.end());
            TreeNode * root=new TreeNode(maxnum);
            int idx=find(nums,maxnum);
            vector<int> vecleft(nums.begin(),nums.begin()+idx);
            root->left=constructMaximumBinaryTree(vecleft);
            vector<int> vecright(nums.begin()+idx+1,nums.end());
            root->right=constructMaximumBinaryTree(vecright);
            return root;
        }
    }
};