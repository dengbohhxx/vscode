/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            queue<TreeNode*> que;
            vector<vector<int> > vec;
            vector<int> row;
            if(pRoot==NULL)
                return vec;
            TreeNode* current=NULL;
            que.push(pRoot);
            while(!que.empty())
            {
                int size=que.size();
                for(int i=0;i<size;i++)
                {
                    current=que.front();
                    row.push_back(current->val);
                    que.pop();
                    if(current->left!=NULL)
                        que.push(current->left);
                    if(current->right!=NULL)
                        que.push(current->right);
                }
                vec.push_back(row);
                row.clear();
            }
            return vec;
        }
    
};