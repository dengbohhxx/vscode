class Solution {
public:
    int getheight(TreeNode* node,int h,bool &res)
    {
        if(node==NULL)
            return 0;

         int lefth=getheight(node->left,h+1,res);
         int righth=getheight(node->right,h+1,res);
         if(abs(lefth-righth)>1)
             res=false;
         return max(lefth,righth)+1;

    }
    bool IsBalanced_Solution(TreeNode* pRoot) {
    
        bool res=true;
        int h=getheight(pRoot,0,res);
        return res;
    }
};