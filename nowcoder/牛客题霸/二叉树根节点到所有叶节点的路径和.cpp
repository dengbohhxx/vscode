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
     * @return int整型
     */
    void dfs(TreeNode* root,vector<int> &s,vector<vector<int> > &vec)
    {
        if(root==NULL)
        {
            return;
        }
        else
        {
            s.push_back(root->val);
            if(root->left==NULL&&root->right==NULL)
                vec.push_back(s);
            if(root->left!=NULL)
                {
                dfs(root->left,s,vec);
                s.pop_back();
                }
            if(root->right!=NULL)
                {
                dfs(root->right,s,vec);
                s.pop_back();
                }
            
        }
    }
    int sum(vector<vector<int> >vec)
    {
        int sum1=0;
        for(int i=0;i<vec.size();i++)
        {
            int temp=0;
            int k=vec[i].size()-1;
            for(int j=0;j<vec[i].size();j++)
            {
                temp+=vec[i][j]*pow(10,k);
                k--;
            }
            sum1+=temp;
        }
        return sum1;
    }
    int sumNumbers(TreeNode* root) {
        // write code here
        vector<int> vec;
        vector<vector<int> >vec1;
        dfs(root,vec,vec1);
        int a=sum(vec1);
        return a;
    }
};