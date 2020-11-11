/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型vector<vector<>>
     */
    void dfs(TreeNode* root,int temp,int sum,vector<int> &row,vector<vector<int> > &vec)
    {
        if(root==NULL)
        {
            return;
         }
         else
         {
            row.push_back(root->val);
            if(root->left==NULL&&root->right==NULL&&(temp+root->val==sum))
            {
                vec.push_back(row);
            }
            dfs(root->left,temp+root->val,sum,row,vec);
            dfs(root->right,temp+root->val,sum,row,vec);
            row.pop_back();
         }
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        // write code here
        vector<vector<int> > vec;
        vector<int> row;
        dfs(root,0,sum,row,vec);
        return vec;
    }
};