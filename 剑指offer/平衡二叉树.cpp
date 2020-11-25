;class Solution {
public:
    int getheight(TreeNode* node,bool &res)
    {
        if(node==NULL)
            return 0;

         int lefth=getheight(node->left,res);
         int righth=getheight(node->right,res);
         if(abs(lefth-righth)>1)
             res=false;
         return max(lefth,righth)+1;

    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
    
        bool res=true;
        int h=getheight(pRoot,res);
        return res;
    }
};