#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int num=n;
        int  h;
        vector<int> vec;
        while(n--)
        {
            cin>>h;
            vec.push_back(h);
        }
        vector<int> dpup(num);
        dpup[0]=1;
        for(int i=1;i<num;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(vec[i]>vec[j])
                    dpup[i]=max(dpup[i],dpup[j]);
            }
            dpup[i]++;
        }
        vector<int> dpdown(num);
        dpdown[num-1]=1;
        for(int i=num-2;i>=0;i--)
        {
            for(int j=num-1;j>i;j--)
            {
                if(vec[i]>vec[j])
                {
                    dpdown[i]=max(dpdown[i],dpdown[j]);
                }
            }
        dpdown[i]++;
        }
        vector<int> out(num);
        for(int i=0;i<num;i++)
        {
            out[i]=num-(dpup[i]+dpdown[i]-1);
        }
        cout<<*min_element(out.begin(),out.end())<<endl;
    }
    return 0;
}