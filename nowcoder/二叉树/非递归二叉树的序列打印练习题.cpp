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
    vector<vector<int> > convert(TreeNode* root) {
        vector<vector<int> > output;
        vector<int> iteration;
        first(root,iteration);
        output.push_back(iteration);
        iteration.clear();
        middle(root,iteration);
        output.push_back(iteration);
        iteration.clear();
        last(root,iteration);
        output.push_back(iteration);
        iteration.clear();
        return output;
    }
    void first(TreeNode* root,vector<int> &iteration)
    {
        stack<TreeNode*> store;
        TreeNode* current=NULL;
        store.push(root);
        while(!store.empty())
        {
            current=store.top();
            iteration.push_back(current->val);
            store.pop();
            if(current->right!=NULL)store.push(current->right); 
            if(current->left!=NULL)store.push(current->left);  
        }
    }
    void middle(TreeNode* root,vector<int> &iteration)
    {
        stack<TreeNode*> store;
        TreeNode* current=root;
        while(!store.empty()||current!=NULL)
        {
            if(current!=NULL)
            {
                store.push(current);
                current=current->left;
            }
            else
            {
                current=store.top();
                iteration.push_back(current->val);
                
                store.pop();
                current=current->right;
            }
        }
    }
    void last(TreeNode* root,vector<int> &iteration)
    {
        stack<TreeNode*> store1,store2;
        TreeNode* current=NULL;
        store1.push(root);
        while(!store1.empty())
        {
            current=store1.top();
            store2.push(current);
            store1.pop();
            if(current->left!=NULL)store1.push(current->left);
            if(current->right!=NULL)store1.push(current->right);
        }
        while(!store2.empty())
        {
            iteration.push_back(store2.top()->val);
            store2.pop();
        }
    }
};