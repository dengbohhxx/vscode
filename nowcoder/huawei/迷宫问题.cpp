#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct cood
{
    int x;
    int y;
    cood(int m,int n):x(x),y(n){}
};
void dfs(vector<vector<int> > vec,vector<vector<int> > &vis,cood index,cood end,vector<cood> &co,vector<cood> &minpath)
{
    if(index.x==end.x&&index.y==end.y)
    {
        if(minpath.empty()||co.size()<minpath.size())
            minpath=co;
        return;
    }
    else
    {
        vis[index.x][index.y]=-1;
        co.push_back(index);
        for(int i=0;i<4;i++)
        {
            switch(i)
            {
                case 0:                    
                    if(index.x>=0&&index.x<=end.x&&index.y-1>=0&&index.y-1<=end.y&&vis[index.x][index.y-1]==0)
                    {
                        dfs(vec,vis,cood(index.x,index.y-1),end,co,minpath);
                        co.pop_back();
                        vis[index.x][index.y]=0;
                    }
                case 1:
                    if(index.x>=0&&index.x<=end.x&&index.y+1>=0&&index.y+1<=end.y&&vis[index.x][index.y+1]==0)
                    {
                        dfs(vec,vis,cood(index.x,index.y+1),end,co,minpath);
                        co.pop_back();
                        vis[index.x][index.y]=0;
                    }
                case 2:
                    if(index.x-1>=0&&index.x-1<=end.x&&index.y>=0&&index.y<=end.y&&vis[index.x-1][index.y]==0)
                    {
                        dfs(vec,vis,cood(index.x-1,index.y),end,co,minpath);
                        co.pop_back();
                        vis[index.x][index.y]=0;
                    }
                case 3:
                    if(index.x+1>=0&&index.x+1<=end.x&&index.y>=0&&index.y<=end.y&&vis[index.x+1][index.y]==0)
                    {
                        dfs(vec,vis,cood(index.x+1,index.y),end,co,minpath);
                        co.pop_back();
                        vis[index.x][index.y]=0;
                    }
            }
                
        }
    }
}
int main()
{
    int m,n;
    while(cin>>m>>n)
    {
        vector<vector<int> > vec(m,vector<int>(n));
        int a=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>a;
                vec[i][j]=a;
            }
        }
        vector<cood> co;
        vector<cood> minpath;
        cood start(0,0);
        cood end(m-1,n-1);
        vector<vector<int> > vis(m,vector<int>(n));
        vis=vec;
        dfs(vec,vis,start,end,co,minpath);
        for(int i=0;i<minpath.size();i++)
        {
            cout<<"("<<minpath[i].x<<","<<minpath[i].y<<")"<<endl;
        }
    }
    
    
    return 0;
}