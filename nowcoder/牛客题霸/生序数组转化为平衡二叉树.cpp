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
     * @param num int整型vector 
     * @return TreeNode类
     */
    TreeNode* sortedArrayToBST(vector<int>& num) {
        // write code here
        if(num.empty())
            return NULL;
        if(num.size()==1)
        {
            TreeNode* node=new TreeNode(num[0]);
            return node;
        }
        int n=num.size();
        int mid=0;
        if(n%2==0)
            mid=(0+n-1)/2+1;
        else
            mid=(0+n-1)/2;
        vector<int> lvec(num.begin(),num.begin()+mid);
        vector<int> rvec(num.begin()+mid+1,num.end());
        TreeNode* head=new TreeNode(num[mid]);
        head->left=sortedArrayToBST(lvec);
        head->right=sortedArrayToBST(rvec);
        return head;
    }
};