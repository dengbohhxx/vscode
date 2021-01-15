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
    int minDepth(TreeNode* root) {
            if(root==NULL)
            {
                return 0;
            }
            queue<TreeNode*> que;
            que.push(root);
            int depth=1;
            while(!que.empty())
            {
                int size=que.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode * cur=que.front();
                    que.pop();
                    if(cur->left==NULL&&cur->right==NULL)
                    {
                        return depth;
                    }
                    if(cur->left!=NULL)
                        que.push(cur->left);
                    if(cur->right!=NULL)
                        que.push(cur->right);

                }
                depth++;
            }
            return depth;
    }
};