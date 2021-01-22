#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
void solve(vector<int> vec,vector<int> &vec1,vector<vector<int> >& vec2,stack<int> &sta,int index,int end)
{
    if(index==end&&sta.empty())
    {
        vec2.push_back(vec1);
        return;
    }
    else
    {
        for(int i=0;i<2;i++)
        {
            switch(i)
            {
                case 0:
                   if(!sta.empty())
                   {
                       int a=sta.top();
                       sta.pop();
                       vec1.push_back(a);
                   }
                   break;
                case 1:
                    if(index<end)
                    {
                   sta.push(vec[index]);
                   solve(vec,vec1,vec2,sta,index+1,end);
                    }
                   break;
            }
        }
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> vec;
        int num;
        int len=n;
        while(n--)
        {
            cin>>num;
            vec.push_back(num);
        }
        sort(vec.begin(),vec.end());
        stack<int> sta;
        vector<int> vec1;
        vector<vector<int> > vec2;
        solve(vec,vec1,vec2,sta,0,len);
        for(int i=0;i<vec2.size();i++)
        {
            for(int j=0;j<vec.size();j++)
            {
                cout<<vec2[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    
    return 0;
}