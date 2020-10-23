/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/

class CheckCompletion {
public:
    bool chk(TreeNode* root) {
        // write code here
        queue<TreeNode*> que;//队列，二叉树按行遍历
        TreeNode* current =NULL;
        que.push(root);
        bool flag=false;//用来标记是否进入左孩子不为空右孩子不为空，则后续均为叶子结点的情况
        while(!que.empty())
        {
            current=que.front();
            que.pop();
            if(current->left!=NULL&&current->right!=NULL)//左右孩子均不为空，压入队列
            {
                que.push(current->left);
                que.push(current->right);
            }
            if(current->left==NULL&&current->right!=NULL)//左孩子为空右孩子不为空，false
            {
                return false;
            }
            if(current->left!=NULL&&current->right==NULL)//左孩子不为空右孩子不为空，则后续均为叶子结点
            {
                if(flag)
                {
                    if(current->left!=NULL||current->right!=NULL)
                        return false;
                }
                flag=true;
                continue;
            }
            if(flag)
              {
               if(current->left!=NULL||current->right!=NULL)
                return false;
              }
        }
        return true;
    }
};