/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckBalance {
public:
    int getheight(TreeNode* root,int h,bool &res)//h为二叉树的层数
    {
        if(root==NULL)
        {
            return h;
        }
        else
        {
            int left=getheight(root->left,h+1,res);
                if(res==false)
                    return h;//如果不是平衡二叉树，返回最深层数
            int right=getheight(root->right,h+1,res);
                if(res==false)
                    return h;
            if(abs(left-right)>1)
            {
                res=false;
            }
           return max(left,right);//返回左右子树中最深的层数
        }
    }
    bool check(TreeNode* root) {
        // write code here
        bool res=true;
        getheight(root,1,res);
        return res;
    }
};