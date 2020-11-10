/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 * };
 */
 
class Solution {
public:
    /**
     *
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<int> midorder(TreeNode* root)
    {
        vector<int> vec;
        stack<TreeNode*> stk;
        TreeNode* current=root;
        while(!stk.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                stk.push(current);
                current=current->left;
            }else
            {   
            current=stk.top();
            stk.pop();
            vec.push_back(current->val);
            current=current->right;
            }
        }
        return vec;
    }
    bool issearch(TreeNode* root)
    {
        if(root==NULL)
            return false;
        vector<int> vec=midorder(root);
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]<vec[i-1])
                return false;
        }
        return true;
    }
    bool isfull(TreeNode* root)
    {
        if(root==NULL)
            return false;
        queue<TreeNode*> que;
        TreeNode* current=NULL;
        que.push(root);
        bool flag=false;
        while(!que.empty())
        {
                current=que.front();
                que.pop();
                if(current->left!=NULL&&current->right!=NULL)
                {
                    que.push(current->left);
                    que.push(current->right);
                }
                else if(current->left==NULL&&current->right!=NULL)
                    return false;
                else
                {
                    if(current->left!=NULL&&current->right==NULL)
                    {
                        while(!que.empty())
                        {
                            current=que.front();
                            que.pop();
                            if(current->left!=NULL||current->right!=NULL)
                                return false;
                        }
                    }
 
                }
        }
        return true;
    }
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        bool res1=issearch(root);
        bool res2=isfull(root);
        vector<bool> res;
        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};