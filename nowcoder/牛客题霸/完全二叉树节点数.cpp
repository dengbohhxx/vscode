/**
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    void nodenum(TreeNode* head,int &k)
    {
        if(head==NULL)
            return;
        else
        {
            int lh=0;
            int rh=0;
            TreeNode* p=head->left;
            while(p!=NULL)
            {
                p=p->left;
                lh++;
            }
            p=head->right;
            while(p!=NULL)
            {
                p=p->left;
                rh++;
            }
            if(lh!=rh)
            {
                k=pow(2,rh)+k;
                nodenum(head->left,k);
            }
            else
            {
                k=k+pow(2,lh);
                nodenum(head->right,k);
            }
        }
    }
    int nodeNum(struct TreeNode* head) {
           if(head==NULL)
               return 0;
        int k=0;
        nodenum(head,k);
        return k;
    }
};