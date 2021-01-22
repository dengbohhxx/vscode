#include<iostream>
#include<vector>
#include<algorithm>
#include <functional>
using namespace std;
int main()
{
    int m=0;
    int n=0;
    int k=0;
    while(cin>>m>>n>>k)
    {
        vector<int> vec;
        int k1=0;
        int i=1;
        int j=1;
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=n;++j)
            {
                if (k1 <k)
                {
                    vec.push_back(i*j);
                    ++k1;
                }
                else 
                {
                    make_heap(vec.begin(),vec.end(),greater<>());
                    if(i*j>vec[0])
                    {
                        pop_heap(vec.begin(),vec.end(),greater<>());
                        vec.pop_back();
                        vec.push_back(i*j);
                        push_heap(vec.begin(),vec.end(),greater<>());
                    }
                    ++k1;
                }
            }
        }
        cout<<vec[0]<<endl;
    }
     
    return 0;
}