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
     * @param root TreeNode类 the root
     * @return int整型vector
     */
    void midorder(TreeNode* root,vector<int> &vec)
    {
        stack<TreeNode*> stk;
        TreeNode* current=root;
        while(!stk.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                stk.push(current);
                current=current->left;
            }
            else
            {
                current=stk.top();
                stk.pop();
                vec.push_back(current->val);
                current=current->right;
            }
        }
    }
    vector<int> findError(TreeNode* root) {
        // write code here
        vector<int> vec;
        vector<int> res(2);
        midorder(root,vec);
        int k=0;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]<vec[i-1])
            {
                k++;
                if(k==1)
                {
                    res[0]=vec[i];
                    res[1]=vec[i-1];
                }
                if(k==2)
                {
                    res[0]=vec[i];
                }
            }
        }
        return res;
    }
};