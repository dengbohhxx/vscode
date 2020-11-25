/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        else
        {
            int lh=TreeDepth(pRoot->left);
            int rh=TreeDepth(pRoot->right);
            return max(lh,rh)+1;
        }
        
    }
};