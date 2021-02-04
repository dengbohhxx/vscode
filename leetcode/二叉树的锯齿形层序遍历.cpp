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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<int> row;
        vector<vector<int> > vec;
        if(root==NULL)
            return vec;
        TreeNode * current=NULL;
        queue<TreeNode*> que;
        que.push(root);
        int k=0;
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
            if(k%2==0)
            {
                vec.push_back(row);
            }
            else
            {
                reverse(row.begin(),row.end());
                vec.push_back(row);
            }
            k++;
            row.clear();
        }
        return vec;
    }
};