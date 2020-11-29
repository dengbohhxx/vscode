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
    void kthNode(TreeNode* pRoot,TreeNode*& knode,int &index,int &k)
    {

        if(pRoot==NULL)
            return;
        kthNode(pRoot->left,knode,index,k);
        index++;
        if(index==k)
        {
            knode=pRoot;
            return;
        }
        if(index<k)
            kthNode(pRoot->right,knode,index,k);
    }
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL||k==0)
            return NULL;
        TreeNode* knode=NULL;
        int index=0;
        kthNode(pRoot,knode,index,k);
        return knode;
    }
};