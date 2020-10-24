/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class FindErrorNode {
public:
    /*
    void mid_order(TreeNode* root,vector<int> &vec)
    {
        if(root==NULL)
            return;
        else
        {
            mid_order(root->left,vec);
            vec.push_back(root->val);
            mid_order(root->right,vec);
        }
    }
    */
    
    void mid_order(TreeNode* root,vector<int> &vec)
    {
        stack <TreeNode*> stk;
        TreeNode * current=root;
        while(!stk.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                stk.push(current);
                current=current->left;
            }
            else
            {
                current=stk.top();
                vec.push_back(current->val);
                stk.pop();
                current=current->right;
            }
        }
    }
    
    vector<int> findError(TreeNode* root) {
        // write code here
        vector<int> vec;
        vector<int> result(2,0);
        int num=0;
        mid_order(root,vec);
        for(size_t i=1;i<vec.size();i++)
        {
            if(vec[i]<vec[i-1])
            {
                num++;
                if(num==1)
                {
                   result[0]=vec[i];
                   result[1]=vec[i-1];
                }
                if(num==2)
                {
                   result[0]=vec[i];
                }
            }
        }
        return result;
    }
};