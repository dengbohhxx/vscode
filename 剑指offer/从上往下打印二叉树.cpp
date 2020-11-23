/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> row;
        if(root==NULL)
            return row;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* current=que.front();
                row.push_back(current->val);
                que.pop();
                if(current->left!=NULL)
                {
                    que.push(current->left);
                }
                if(current->right!=NULL)
                {
                    que.push(current->right);
                }
            }
        }
        return row;
    }
};