/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node * clone(Node * node)
    {
        if(node==NULL)
            return node;
        if(used[node->val])
        {
            return used[node->val];
        }
        Node * root=new Node(node->val);
        used[node->val]=root;
        for(int i=0;i<node->neighbors.size();i++)
        {
            root->neighbors.push_back(clone(node->neighbors[i]));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        used.resize(101);
        return clone(node);
    }
private:
    vector<Node *> used;
};