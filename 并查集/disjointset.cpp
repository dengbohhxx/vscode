#include<iostream>
#include<vector>
using namespace std;
//基础版本
/*
class Disjointset//基础版本
{
    public:
    Disjointset(vector<int > vec)//初始化
    {
        int size=vec.size();
        for(int i=0;i<size;i++)
        {
            parent.push_back(vec[i]);
        }
    }
    int find(int x)//查找
    {
        //return parent[x]==x?x:find(parent[x]);
        while(x!=parent[x])
        {
            x=parent[x];
        }
        return x;
    }
    void to_union(int x1,int x2)//合并
    {
        int p1=find(x1);
        int p2=find(x2);
        if(p1==p2)
            return ;
        else
        {
            parent[p1]=p2;
        }
    }

    bool is_same(int e1,int e2)
    {
        return find(e1)==find(e2);
    }

    private:
        vector<int> parent;
};
*/

class Disjointset
{
    public:
    Disjointset(vector<int > vec)//初始化
    {
        int size=vec.size();
        for(int i=0;i<size;i++)
        {
            parent.push_back(vec[i]);
            rank.push_back(1);
        }
        this->count=size;
    }
    int find(int x)//查找
    {
        //return parent[x]==x?x:find(parent[x]);
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
    void to_union(int x1,int x2)//合并
    {
        int p1=find(x1);
        int p2=find(x2);
        if(p1==p2)
            return ;
        else
        { // 小树接到大树下面，较平衡
            if(rank[p1]>rank[p2])
            {
                parent[p2]=p1;
                rank[p1]+=rank[p2];
            }
            else
            {
                parent[p1]=p2;
                rank[p2]+=rank[p1];
            }
        count--;    
        }
    }

    bool connected (int e1,int e2)
    {
        return find(e1)==find(e2);
    }
    
    int counted()
    {
        return  count;
    }

    private:
        vector<int> parent; //存储一棵树
        vector<int> rank;//// 记录树的“重量”
        int count;//连通分量个数
};
int main()
{
    
    int a[9]={0,0,0,3,3,5,6,2,7};
    vector<int> vec(a,a+9);
    Disjointset disjset(vec);
    cout<<disjset.find(8)<<endl;





    return 0;
}