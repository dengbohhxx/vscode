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
     * @param root TreeNode类 the root of binary tree
     * @return int整型vector<vector<>>
     */
    void preorder(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            vec.push_back(root->val);
            preorder(root->left,vec);
            preorder(root->right,vec);
        }
    }
    void midorder(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            
            midorder(root->left,vec);
            vec.push_back(root->val);
            midorder(root->right,vec);
        }
    }
    void lastorder(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            
            lastorder(root->left,vec);
            
            lastorder(root->right,vec);
            vec.push_back(root->val);
        }
    }
    vector<vector<int> > threeOrders(TreeNode* root) {
        // write code here
        vector<vector<int> >vec;
        vector<int> row;
        preorder(root,row);
        vec.push_back(row);
        row.clear();
        midorder(root,row);
        vec.push_back(row);
        row.clear();
        lastorder(root,row);
        vec.push_back(row);
        row.clear();
        return vec;
    }
};