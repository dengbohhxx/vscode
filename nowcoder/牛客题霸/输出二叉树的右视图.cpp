class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 求二叉树的右视图
     * @param xianxu int整型vector 先序遍历
     * @param zhongxu int整型vector 中序遍历
     * @return int整型vector
     */
    struct listnode
    {
        int val;
        struct listnode *left;
        struct listnode *right;
        listnode(int x):val(x),left(NULL),right(NULL){}
    };
    int find(vector<int> vec,int val)
    {
        int n=vec.size();
        int res=-1;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==val)
            {
                res=i;
                break;
            }
        }
        return res;
    }
    listnode * help(vector<int> xianxu, vector<int> zhongxu)
    {
        if(xianxu.empty()||zhongxu.empty())
            return NULL;
        listnode *head=new listnode(xianxu[0]);
        listnode * p=head;
        int i=find(zhongxu,xianxu[0]);
        vector<int> preleft(xianxu.begin()+1,xianxu.begin()+i+1);
        vector<int> preright(xianxu.begin()+i+1,xianxu.end());
        vector<int> midleft(zhongxu.begin(),zhongxu.begin()+i);
        vector<int> midright(zhongxu.begin()+i+1,zhongxu.end());
        head->left=help(preleft,midleft);
        head->right=help(preright,midright);
        return head;
    }
    vector<vector<int> > bfs(listnode * head)
    {
        vector<vector<int> > vec;
        vector<int> row;
        queue<listnode *> que;
        que.push(head);
        while(!que.empty())
        {
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                listnode * temp=que.front();
                que.pop();
                row.push_back(temp->val);
                if(temp->left!=NULL)
                    que.push(temp->left);
                if(temp->right!=NULL)
                    que.push(temp->right);
            }
            vec.push_back(row);
            row.clear();
        }
        return vec;
    }
    vector<int> solve(vector<int>& xianxu, vector<int>& zhongxu) {
        // write code here
        auto head=help(xianxu,zhongxu);
        auto vec=bfs(head);
        vector<int> res;
        for(int i=0;i<vec.size();i++)
        {
            res.push_back(vec[i].back());
        }
        return res;
    }
};