/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int find(vector<int> vec,int val)
    {
        int size=vec.size();
        for(int i=0;i<size;i++)
        {
            if(vec[i]==val)
            {
                return i;
            }
        }
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {

        if(pre.size()==0||vin.size()==0)
            return NULL;

        TreeNode * head=new TreeNode(pre[0]);
        TreeNode * p=head;
        int i=find(vin,pre[0]);
        vector<int> preleft(pre.begin()+1,pre.begin()+i+1);
        vector<int> vinleft(vin.begin(),vin.begin()+i);
        vector<int> preright(pre.begin()+i+1,pre.end());
        vector<int> vinright(vin.begin()+i+1,vin.end());
        p->left=reConstructBinaryTree(preleft,vinleft);
        p->right=reConstructBinaryTree(preright,vinright);
        return head;
    }
};