/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // 特殊输入
        if(pNode == nullptr)
            return nullptr;

        /* 寻找结果 */
        // 如果节点有右子节点，则右子节点的最左节点是该节点的下一个节点
        // 如果节点无右子节点，但该节点是其父节点的左子节点，则父节点是该节点的下一个节点
        // 如果节点无右子节点，且该节点是其父节点的右子节点，则沿着父节点向上遍历，满足XXX的父节点是其该节点的下一个节点
        TreeLinkNode * res = NULL;
        if(pNode->right != NULL)
        {
            TreeLinkNode* node_right = pNode->right;
            while(node_right ->left != NULL)
            {
                node_right = node_right->left;
            }
            res = node_right;
        }

        else if(pNode->next != NULL)
        {
            // 当前节点和当前节点的父节点
            TreeLinkNode * current = pNode;
            TreeLinkNode * parent = pNode->next;

            while(parent!=NULL && current == parent->right)
            {
                current = parent;
                parent = parent ->next;
            }

            res = parent;
        }
        return res;
    }
};