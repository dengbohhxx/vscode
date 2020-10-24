/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class LongestDistance {
public:
    vector<int> recurfind(TreeNode* root)
    {
        vector<int> vec(2,0);
        if(root==NULL)
        {
            vec[0]=0;
            vec[1]=0;
            return vec;
        }
        else
        {
            vector<int> left=recurfind(root->left);
            vector<int> right=recurfind(root->right);
            vec[0]=max(left[0],right[0])+1;
            vec[1]=max(max(left[1],right[1]),left[0]+right[0]+1);
        }
        
        return vec;
    }
    
    int findLongest(TreeNode* root) {
        // write code here
       
        if(root==NULL)
            return 0;
        vector<int> vec=recurfind(root);
        return vec[1];
    }
};