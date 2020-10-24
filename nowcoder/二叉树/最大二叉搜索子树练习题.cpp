/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class MaxSubtree {
public:
    TreeNode* getMax(TreeNode* root) {
        // write code here
        int record[3] = {0,0,0};
        if(root == NULL) 
            return NULL;
         
        return getMax(root,record);
         
    }
    TreeNode* getMax(TreeNode* root,int*record){
        if(root == NULL) {
            record[0] = 0;
            record[1] = INT_MAX;//最小
            record[2] = INT_MIN;//最大
             
            return NULL;
        }
        int val = root->val;
         //左子树
        TreeNode*lNode = getMax(root->left,record);
        int lsize=record[0];
        int lmin=record[1];
        int lmax=record[2];
        //右子书
        TreeNode*rNode = getMax(root->right,record);
        int rsize=record[0];
        int rmin = record[1];
        int rmax=record[2];
        //中
        record[1] = min(lmin,val);//???
        record[2] = max(rmax,val);
        //遍历到该头节点，该头结点的左孩子是所对应的左子树的最大搜索二叉子树的节点，该头节点的右孩子
        //是所对应的的右子树的最大搜索二叉子树的节点。并且该头结点的值比左边整个子树的最大值还要大，比
        //右边整个子树的最小值还要小，那么该头节点所代表的整颗树即为最大搜索二叉子树，返回头节点即可。
        if(lNode == root->left&&rNode == root->right&&lmax<val&&val<rmin)
        {
            record[0] = lsize+rsize+1;
             
            return root;
        }else
        {
            if(lsize>rsize)
            {
                record[0] = lsize;
                 
                return lNode;
            }
            else
            {
                record[0] = rsize;
                 
                return rNode;
            }
        }
    }
};