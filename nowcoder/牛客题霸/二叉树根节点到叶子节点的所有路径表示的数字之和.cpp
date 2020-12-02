/*


class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
    void dfs(TreeNode* root,vector<string>&vec,string str)//如果不是引用，那么在退回时就不用pop_back，退回到上一层会自动pop_back；
    {
        if(root==NULL)
            return;
        str.push_back(root->val+'0');
        if(root->left==NULL&root->right==NULL)
        {
            vec.push_back(str);
            return;
        }
        dfs(root->left,vec,str);
        dfs(root->right,vec,str);
        //str.pop_back();
    }
    int to_int(string str)
    {
        int res=0;
        int base=1;
        for(int i=str.size()-1;i>=0;i--)
        {
            res+=(str[i]-'0')*base;
            base*=10;
        }
        return res;
    }
    int sumNumbers(TreeNode* root) {
        // write code here
        if(root==NULL)
            return 0;
        vector<string> vec;
        string s="";
        dfs(root,vec,s);
        int k=0;
        for(int i=0;i<vec.size();i++)
        {
            k+=to_int(vec[i]);
        }
        return k;
    }
};
*/
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
    void dfs(TreeNode* root,vector<string>&vec,string &str)//如说str是引用，那记得得pop_back;每个left,right分支都得pop—back，不是只在最后
    {
        if(root==NULL)
            return;
        str.push_back(root->val+'0');
        if(root->left==NULL&root->right==NULL)
        {
            vec.push_back(str);
            return;
        }
        if(root->left!=NULL)
        {
            dfs(root->left,vec,str);
            str.pop_back();
        }
        if(root->right!=NULL)
        {
        dfs(root->right,vec,str);
        str.pop_back();
        }
    }
    int to_int(string str)
    {
        int res=0;
        int base=1;
        for(int i=str.size()-1;i>=0;i--)
        {
            res+=(str[i]-'0')*base;
            base*=10;
        }
        return res;
    }
    int sumNumbers(TreeNode* root) {
        // write code here
        if(root==NULL)
            return 0;
        vector<string> vec;
        string s="";
        dfs(root,vec,s);
        int k=0;
        for(int i=0;i<vec.size();i++)
        {
            k+=to_int(vec[i]);
        }
        return k;
    }
};