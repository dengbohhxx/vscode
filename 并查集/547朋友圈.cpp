class Solution {
public:
    int find(vector<int> &vec,int x)
    {
        if(vec[x]==-1)
            return x;
        else
            return find(vec,vec[x]);
    }


    void union1(vector<int> &vec,int m,int n)
    {
        int pn=find(vec,m);
        int pm=find(vec,n);
        if(pn!=pm)
            vec[pn]=pm;
    }

    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        vector<int> parent(n,-1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j]==1&&i!=j)
                {
                    union1(parent,i,j);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
                count++;
        }
        return count;
    }
};