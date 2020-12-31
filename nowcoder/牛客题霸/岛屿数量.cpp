/*
class Solution {
public:

    void dfs(vector<vector<char> >& grid,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        grid[i][j]='0';
        if(i-1>=0&&grid[i-1][j]=='1')
            dfs(grid,i-1,j);
        if(i+1<m&&grid[i+1][j]=='1')
            dfs(grid,i+1,j);
        if(j-1>=0&&grid[i][j-1]=='1')
            dfs(grid,i,j-1);
        if(j+1<n&&grid[i][j+1]=='1')
            dfs(grid,i,j+1);
    }
    int solve(vector<vector<char> >& grid) {
        // write code here
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        int num=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    num++;
                    dfs(grid,i,j);
                }
            }
        }
        return num;
    }
};
*/
#include <iostream>
#include <vector>
using namespace std;
class UnionFind
{
    public:
    UnionFind(vector<vector<char> >& grid)
    {
        count=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    parent.push_back(i*n+j);
                    count++;
                }
                else
                {
                    parent.push_back(-1);
                }
                size.push_back(1);
            }
        }
    }
    int find(int x)
    {
        int son=x;
        int temp=0;
        while(x!=parent[x])
        {
            x=parent[x];
        }
        while(son!=x)
        {
            temp=parent[son];
            parent[son]=x;
            son=temp;
        }
        return x;
    }
    void union1(int x1,int x2)
    {
        int p1=find(x1);
        int p2=find(x2);
        if(p1==p2)
            return;
        else
        {
            if(size[p1]>=size[p2])
            {
                parent[p2]=p1;
                size[p1]+=size[p2];
            }
            else
            {
                parent[p1]=p2;
                size[p2]+=size[p1];
            }
            count--;
        }
    }
    bool connected(int e1,int e2)
    {
        return find(e1)==find(e2);
    }
    int counted()
    {
        return  count;
    }
    private:
        vector<int> parent;
        vector<int> size;
        int count;
};
int solve(vector<vector<char> >& grid) {
        // write code here
        int m=grid.size();
        if(m==0)
            return 0;
        int n=grid[0].size();
        UnionFind uf(grid);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    grid[i][j]='0';
                    if(i-1>=0&&grid[i-1][j]=='1')
                        uf.union1(i*n+j,(i-1)*n+j);
                    if(i+1<m&&grid[i+1][j]=='1')
                        uf.union1(i*n+j,(i+1)*n+j);
                    if(j-1>=0&&grid[i][j-1]=='1')
                        uf.union1(i*n+j,i*n+j-1);
                    if(j+1>=0&&grid[i][j+1]=='1')
                        uf.union1(i*n+j,i*n+j+1);
                }
            }
        }
        return uf.counted();
    }
int main()
{
    int n=0;
    while(cin>>n)
    {
        char num=0;
        vector<vector<char> > vec(n,vector<char>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>vec[i][j];
            }
        }
    int a=solve(vec);
    cout<<a<<endl;
    }
    return 0;
}