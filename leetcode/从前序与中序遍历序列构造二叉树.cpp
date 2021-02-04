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
    int find(vector<int>  inorder,int tartget)
    {
        int n=inorder.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            if(inorder[i]==tartget)
                break;
        }
        return i;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
                if(preorder.size()==0&&inorder.size()==0)
                    return NULL;
                else
                {
                    TreeNode * root=new TreeNode(preorder[0]);
                    int idx=find(inorder,preorder[0]);
                    vector<int> preleft(preorder.begin()+1,preorder.begin()+idx+1);
                    vector<int> inleft(inorder.begin(),inorder.begin()+idx);
                    root->left=buildTree(preleft,inleft);
                    vector<int> preright(preorder.begin()+idx+1,preorder.end());
                    vector<int> inright(inorder.begin()+idx+1,inorder.end());
                    root->right=buildTree(preright,inright);
                    return root;
                }
    }
};