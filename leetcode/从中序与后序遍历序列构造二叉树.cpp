/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int find(vector<int>  postorder,int tartget)
    {
        int n=postorder.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            if(postorder[i]==tartget)
                break;
        }
        return i;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.size()==0&&postorder.size()==0)
                    return NULL;
                else
                {

                    TreeNode * root=new TreeNode(postorder.back());
                    int idx=find(inorder,postorder.back());
                    vector<int> postleft(postorder.begin(),postorder.begin()+idx);
                    vector<int> inleft(inorder.begin(),inorder.begin()+idx);
                    root->left=buildTree(inleft,postleft);
                    vector<int> postright(postorder.begin()+idx,postorder.end()-1);
                    vector<int> inright(inorder.begin()+idx+1,inorder.end());
                    root->right=buildTree(inright,postright);
                    return root;
                }
    }
};