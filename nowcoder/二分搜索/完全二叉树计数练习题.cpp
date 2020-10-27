/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class CountNodes {
public:
    int count(TreeNode* root) {
        // write code here
        int num=0;
        if(root==NULL)
            return 0;
        int l_height=0;
        TreeNode * leftnode=root->left;
        while(leftnode!=NULL)
        {
            l_height++;
            leftnode=leftnode->left;
        }
        int r_height=0;
        TreeNode * rightnode=root->right;
        while(rightnode!=NULL)
        {
            r_height++;
            rightnode=rightnode->left;
        }
        if(l_height==r_height)
        {
            num=pow(2,l_height)-1+count(root->right)+1;
        }
        if(l_height!=r_height)
        {
            num=pow(2,r_height)-1+count(root->left)+1;
        }
        return num;
    }
};