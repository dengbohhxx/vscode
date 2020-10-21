/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreeToSequence {
public:
    void pre_order(TreeNode * head,vector<int>& vec)
    {
        //struct TreeNode * tf=head;
        if(head==NULL)
            return ;
        else
        {
            vec.push_back(head->val);
            pre_order(head->left,vec);
            pre_order(head->right,vec);
        }
    }
    void mid_order(TreeNode * head,vector<int>& vec)
    {
        //struct TreeNode * tf=head;
        if(head==NULL)
            return ;
        else
        {
            mid_order(head->left,vec);
            vec.push_back(head->val);
            mid_order(head->right,vec);
        }
    }
    void last_order(TreeNode * head,vector<int>& vec)
    {
        //struct TreeNode * tf=head;
        if(head==NULL)
            return ;
        else
        {
            last_order(head->left,vec);
            last_order(head->right,vec);
            vec.push_back(head->val);
        }
    }
    vector<vector<int> > convert(TreeNode* root) 
    {
        // write code here
        vector<vector<int> > vec1(3,vector<int>() );
         pre_order(root,vec1[0]);
        mid_order(root,vec1[1]);
        last_order(root,vec1[2]);
        return vec1;
    }
};