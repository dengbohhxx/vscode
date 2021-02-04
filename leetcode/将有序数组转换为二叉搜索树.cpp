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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
            if(nums.size()==0)
                return NULL;
            else
            {
                int n=nums.size();
                TreeNode * root=new TreeNode(nums[n/2]);
                vector<int> vecleft(nums.begin(),nums.begin()+n/2);
                vector<int> vecright(nums.begin()+n/2+1,nums.end());
                root->left=sortedArrayToBST(vecleft);
                root->right=sortedArrayToBST(vecright);
                return root;
            }
    }
};