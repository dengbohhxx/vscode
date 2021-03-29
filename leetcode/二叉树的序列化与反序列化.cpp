/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<string>
class Codec {
public:
    string str;
    void dfs1(TreeNode *root)
    {
        if(root==NULL)
        {
            str+="null,";
            return;
        }
        str=(str+to_string(root->val)+',');
        dfs1(root->left);
        dfs1(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs1(root);
        return str;
    }

    // Decodes your encoded data to tree.
    queue<string> Q;
    TreeNode *dfs2()
    {
        string temp=Q.front();
        Q.pop();
        if(temp=="null")
        {
            return NULL;
        }
        TreeNode * root=new TreeNode(stoi(temp));
        root->left=dfs2();
        root->right=dfs2();
        return root;
    }
    TreeNode* deserialize(string data) {
        int i = 0,  j = 0;
        while(i < data.size())
        {
            if (data[i] != ',')
                i ++;
            else
            {
                string tmp = data.substr(j, i - j);
                Q.push(tmp);
                i ++;
                j = i;
            }
        }
        if (j != i)
        {
            string tmp = data.substr(j, i - j);
            Q.push(tmp);
        }
        return dfs2();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));