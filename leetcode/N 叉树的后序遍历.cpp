/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
void post(Node *root,vector<int> &vec)
    {
        if(root==NULL)
        {
            return;
        }
        int n=root->children.size();
        for(int i=0;i<n;i++)
        {
            post(root->children[i],vec);
        }
        vec.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> vec;
        post(root,vec);
        return vec;
    }
};