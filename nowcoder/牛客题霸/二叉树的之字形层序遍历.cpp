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
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        // write code here
        queue<TreeNode*> que;
        vector<vector<int> > vec1;
        vector<int> vec;
        if(root==NULL)
            return vec1;
        TreeNode* current;
        que.push(root);
        int flag=0;
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                current=que.front();
                que.pop();
                vec.push_back(current->val);
                if(current->left!=NULL)
                    que.push(current->left);
                if(current->right!=NULL)
                    que.push(current->right);
            }
            if(flag%2==1)
                reverse(vec.begin(),vec.end());
            flag++;
            vec1.push_back(vec);
            vec.clear();
        }
        return vec1;
    }
};