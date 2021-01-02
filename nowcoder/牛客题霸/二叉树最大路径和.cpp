/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 * };
 */

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    int helper(TreeNode* root,int &m) //计算过当前结点的最大路径和
    {
        if(!root)return 0;
        
        int l=helper(root->left,m);   //过当前结点左子结点的最大路径和
        int r=helper(root->right,m);  //过当前结点右子结点的最大路径和
        
        int curSum=max(root->val,max(l+root->val,r+root->val));  //过当前结点的最大路径和
 
        int curMax=max(curSum,l+r+root->val); //如果将当前结点作为根结点，就要考虑横跨的情况
            
        m=max(m,curMax); //更新最大值
        
        return curSum; //返回过当前结点的最大路径和
}
    int maxPathSum(TreeNode* root) {
        // write code here
         if(!root)return 0;
        int m=INT_MIN;  //存放最大路径和
        
        helper(root,m); //将m传入，便于更新最大值m
        
        return m;
    }
};