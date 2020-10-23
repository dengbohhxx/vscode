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
    int getheight(TreeNode * root,int h,bool &res)
    {
        if(root==NULL)
            return 0;
        else
        {
            int lh=getheight(root->left,h+1,res);
            //if(res==false)
                //return h;
            int rh=getheight(root->right,h+1,res);
            //if(res==false)
                //return h;
            if(abs(lh-rh)>1)
                res=false;
            return max(lh,rh)+1;
        }
    }
    bool check(TreeNode* root) {
        // write code here
        bool res=true;
        getheight(root,0,res);
        return res;
    }
};