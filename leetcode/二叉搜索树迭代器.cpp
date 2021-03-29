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
class BSTIterator {
public:
    void midorder(TreeNode * root,vector<int> &vec)
    {
        if(root==NULL)
        {
            return;
        }
        midorder(root->left,vec);
        vec.push_back(root->val);
        midorder(root->right,vec);
    }
    BSTIterator(TreeNode* root) {
        midorder(root,vec);
        idx=0;
    }
    
    int next() {
        return vec[idx++];
    }
    
    bool hasNext() {
        return idx<=vec.size();
    }
private:
    vector<int> vec;
    int idx;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */