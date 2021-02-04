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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> row;
        vector<vector<int> > vec;
        vector<int> res;
        if(root==NULL)
            return res;
        TreeNode * current=NULL;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                current=que.front();
                que.pop();
                row.push_back(current->val);
                if(current->left!=NULL)
                {
                    que.push(current->left);
                }
                if(current->right!=NULL)
                {
                    que.push(current->right);
                }
            }
            vec.push_back(row);
            row.clear();
        }
        for(int i=0;i<vec.size();i++)
        {
            res.push_back(vec[i].back());
        }
        return res;
    }
};