/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class IdenticalTree {
public:
    bool chkIdentical(TreeNode* A, TreeNode* B)
    {
        /*string str1,str2;
        TreeToString(A,str1);
        TreeToString(B,str2);        
        if(str1.find(str2)!=string::npos){
            return true;
        }else{
            return false;
        }
    }
    void TreeToString(TreeNode* root , string &str){
        if(root == NULL){
            str+="#!";
            return;
        }
        str=str+to_string(root->val)+'!';
        TreeToString(root->left , str);
        TreeToString(root->right, str);        
    }
    };*/
        // write code here 
        bool res=false;
        if(A!=NULL)
        {
            if(res==false&&A->val==B->val)
                res=helper(A,B);
            if(res==false&&A->left!=NULL)
                res=chkIdentical(A->left,B);
            if(res==false&&A->right!=NULL)
                res=chkIdentical(A->right,B);
        }
        return res;
    }
    bool helper(TreeNode* A,TreeNode* B)
    {
        if(A==NULL&&B==NULL)//两个节点都为空
            return true;
        if((A!=NULL&&B==NULL)||(A==NULL&&B!=NULL))//一个为空 一个不为空
            return false;
       
        if(A->val!=B->val)//两个节点都不为空但是节点值不行等
            return false;
        //相等的情况
        return helper(A->left,B->left)&&helper(A->right,B->right);
    }
};