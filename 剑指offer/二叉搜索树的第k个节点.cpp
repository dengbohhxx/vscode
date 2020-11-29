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
    void middle(TreeNode* pRoot,vector<TreeNode*> &vec)
    {
        if(pRoot==NULL)
            return;
        else
        {
            middle(pRoot->left,vec);
            vec.push_back(pRoot);
            middle(pRoot->right,vec);
        }
        
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        vector<TreeNode*> vec;
        if(pRoot==NULL)
            return pRoot;
        middle(pRoot,vec);
        if(k>vec.size()||k<=0)
            return NULL;
        else
        return vec[k-1];
    }

    
};