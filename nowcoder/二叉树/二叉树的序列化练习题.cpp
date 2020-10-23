/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToString {
public:
    string toString(TreeNode* root) {
        string str;
        preOrderToString(root,str);
        return str;
         
    }
    void preOrderToString(TreeNode* root,string &str){
        if(root==NULL){
            str+="#!";
             
            return;
        }
        str+=to_string(root->val)+"!"; 
        preOrderToString(root->left,str);
        preOrderToString(root->right,str);
    }
};