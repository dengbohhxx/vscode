#include<iostream>
#include<vector>
using namespace std;
void solve(vector<int> vec,int index,int start,int end,bool &res)
{
    if(index==vec.size()&&start==end)//仔细判断终止条件应该是index==vec.size()而不是index==vec.size()-1，要把最后一个元素加进来
    {
        res=true;
        return;
    }
    if(index==vec.size()&&start!=end)
        return ;
    for(int i=0;i<2;i++)
      {
        switch(i)
        {
         case 0:
           solve(vec,index+1,start+vec[index],end,res);
         case 1:
           solve(vec,index+1,start-vec[index],end,res);
        }
     }
}
int main()
{
    int num=0;
    while(cin>>num)
    {
        vector<int> vec;
        while(num--)
        {
            int n=0;
            cin>>n;
            vec.push_back(n);
        }
        int k=0;
        vector<int> vec1;
        for(int i=0;i<vec.size();i++)
        {
            if(vec[i]%5==0&&vec[i]!=0)
                k+=vec[i];
            else if(vec[i]%3==0&&vec[i]%5!=0&&vec[i]!=0)
                k-=vec[i];
            else if(vec[i]!=0)
                vec1.push_back(vec[i]);
        }
        bool res=false;
        solve(vec1,0,k,0,res);
        if(res==true)
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
    }
    return 0;
}