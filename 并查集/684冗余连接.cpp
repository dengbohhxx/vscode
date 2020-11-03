class Solution {
public:
    int find(vector<int> &vec,int x)
    {
        if(vec[x]==-1)
            return x;
        else
            return find(vec,vec[x]);
    }
    bool union1(vector<int> &vec,int m,int n)
    {
        bool res=false;
        int pm=find(vec,m-1);
        int pn=find(vec,n-1);
        if(pm!=pn)
        {
            vec[pn]=pm;
        }
        else
            res=true;
        return res;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int size=edges.size();
        int max=0;
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<2;j++)
            {
                if(max<edges[i][j])
                    max=edges[i][j];
            }
        }
        vector<int> parent(max,-1);
        vector<int> res(2);
        for(int i=0;i<size;i++)
        {
            if(union1(parent,edges[i][0],edges[i][1]))
                    {
                        res[0]=edges[i][0];
                        res[1]=edges[i][1];
                        break;
                    }
        }
        return res;
    }
};