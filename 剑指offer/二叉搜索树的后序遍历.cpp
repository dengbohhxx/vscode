class Solution {
public:
    
    bool bst(vector<int> sequence,int start,int end)
    {
        int root=sequence[end];//最后一个为根节点
        int i=0;
        for(;i<=end-1;i++)//左侧小于根节点，右侧大于根节点
        {
            if(sequence[i]>root)
                break;
        }
        int j=i;
        for(;j<=end;j++)
        {
            if(sequence[j]<root)//如果右侧有小于根节点的值，返回false
                return false;
        }
        bool left=true;
        if(start<i-1)
            left=bst(sequence,start,i-1);
        bool right=true;
        if(j<end)
            right=bst(sequence,j,end-1);
        return left&&right;
    }
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==0)
           return false;
        int size=sequence.size();
        return bst(sequence,0,size-1);
    }
};