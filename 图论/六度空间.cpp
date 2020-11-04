#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <iomanip>
using namespace std;
int bfs(int n,vector<bool> &vis,vector<vector<int> > &vec)
{
    vis[n]=true;
    std::queue<int> que;
    que.push(n); 
    int count=1;
    int level=0;
    int last=n;
    int tail=0;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int j=1;j<=vis.size();j++)
        {
            if(vec[v][j]==1)
            {
                if(vis[j]==false)
                {
                    vis[j]=true;
                    que.push(j);
                    count++;
                    tail=j;
                }
             }
         }
        if(v==last)
        {
            level++;
            last=tail;
        }
        if(level==6)
        {
            break;
        }
    }
    return count;
}
int main()
{
    int v=0;
    int e=0;
    while(cin>>v>>e)
    {
        int m=0;
        int n=0;
        vector<vector<int> > vec(v+1,vector<int>(v+1));
        while(e--)
        {
            cin>>m>>n;
            vec[m][n]=1;
            vec[n][m]=1;
        }
       
        for(int i=1;i<=v;i++)
        {
             vector<bool> vis(v,false);
            float num=float(bfs(i,vis,vec)*1.00000/v)*100;
            cout<<i<<": " <<setiosflags(ios::fixed)<<setprecision (2)<<num<<"%"<<endl;
        }    
        
    }  
    return 0;
}