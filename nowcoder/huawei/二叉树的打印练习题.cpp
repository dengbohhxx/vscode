/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class TreePrinter {
public:
	vector<vector<int> > printTree(TreeNode* root) {
		// write code here
		vector<vector<int> > output;
		vector<int> row;
		queue <TreeNode*> q;
		if (root == NULL)
			return output;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			for (int i = 0; i<size; i++)
			{
				TreeNode* current = q.front();
				row.push_back(current->val);
				q.pop();
				if (current->left != NULL)
					q.push(current->left);
				if (current->right != NULL)
					q.push(current->right);
			}
			output.push_back(row);
			row.clear();
		}
		return output;
	}
};