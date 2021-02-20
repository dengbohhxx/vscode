class UnionFind
{
public:
    UnionFind(int n)
    {
        this->count1=n;
        for(int i=0;i<n;i++)
        {
            parent.push_back(i);
            size.push_back(i);
        }
    }
    int count()
    {
        return this->count1;
    }
    int find(int x)
    {
        while(x!=parent[x])
        {
            parent[x]=parent[parent[x]];
            x=parent[x];
        }
        return x;
    }
    void union1(int p,int q)
    {
        int rootp=find(p);
        int rootq=find(q);
        if(rootp==rootq)
            return;
        if(size[rootp]>size[rootq])
        {
            parent[rootq]=rootp;
            size[rootp]+=size[rootq];
        }
        else
        {
            parent[rootp]=rootq;
            size[rootq]+=size[rootp];
        }
        count1--;
    }
    bool connected(int p,int q)
    {
        int rootp=find(p);
        int rootq=find(q);
        return rootp==rootq;
    }
private:
    int count1;
    vector<int> parent;
    vector<int> size;
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        UnionFind uf(26);
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='=')
            {
                char x=equations[i][0];
                char y=equations[i][3];
                uf.union1(x-'a',y-'a');
            }
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!')
            {
                char x=equations[i][0];
                char y=equations[i][3];
                if(uf.connected(x-'a',y-'a'))
                {
                    return false;
                }
            }
        
        }
        return true;
    }
};