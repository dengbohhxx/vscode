/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
/*class Solution {
public:
    void path(TreeNode* root,vector<int> &vec1,vector<vector<int> > &vec,int expectNumber)
    {
        bool leaf=root->left==NULL&&root->right==NULL;
        vec1.push_back(root->val);
        if(leaf)
        {
            if(expectNumber==root->val)
                vec.push_back(vec1);
            return;
        }
         if(root->left)
         path(root->left,vec1,vec,expectNumber-root->val);
         vec1.pop_back();
         if(root->right)
         path(root->right,vec1,vec,expectNumber-root->val);
         vec1.pop_back();
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
          vector<int> vec1;
          vector<vector<int> > vec;
        if(root==NULL)
            return vec;
          path(root,vec1,vec,expectNumber);
          return vec;
    }
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) 
    {
        vector<vector<int> > res;
        if(root==NULL)
            return res;
        int currentsum=0;
        vector<int> temp;
        FindPath1(res,root,expectNumber,temp,currentsum);
        return res;
    }
     void  FindPath1(vector<vector<int> > &res,TreeNode* root,int expectNumber,vector<int> &temp,int current)
     {
         current+=root->val;
         temp.push_back(root->val);
         if(Isleaf(root)&&expectNumber==current)
             res.push_back(temp);
         if(root->left!=NULL)
         {
             FindPath1(res,root->left,expectNumber, temp,current);
            // temp.push_back(root->val);
         }
         
         if(root->right!=NULL)
          {
             FindPath1(res,root->right,expectNumber, temp,current);
             //temp.push_back(root->val);
          }
         temp.pop_back();
     } 
    bool Isleaf(TreeNode* Node)
    {
        if(Node->left==NULL&&Node->right==NULL) 
            return true;
        else 
            return false;
    }
};