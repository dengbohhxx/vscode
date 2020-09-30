#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> vec;
        int num=0;
        while(n--)
        {
            cin>>num;
            vec.push_back(num);
        }    
        int flag=0;
        cin>>flag;
        if(flag==0)
        {
            sort(vec.begin(),vec.end());
        }
        if(flag==1)
        {
            sort(vec.begin(),vec.end());
            reverse(vec.begin(),vec.end());
        }
        for(int i=0;i<vec.size()-1;i++)
        {
            cout<<vec[i]<<" ";
        }
        cout<<vec[vec.size()-1]<<endl;
    }
    return 0;
}