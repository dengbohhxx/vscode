#include<iostream>
#include<list>
using namespace std;
    int ysf(int n, int m) {
        // write code here
        list<int> li;
        for(int i=1;i<=n;i++)
        {
            li.push_back(i);
        }
        list<int>::iterator iter=li.begin();
        while(li.size()>1)
        {
            for(int i=1;i<m;i++)
            {
                iter++;
                
                if(iter==li.end())
                {
                    iter=li.begin();
                }
            }
            iter=li.erase(iter);
            if(iter==li.end())
                iter=li.begin();
        }
        return *iter;
    }
main()
{
    int a=ysf(10000,9999);
    cout<<a<<endl;
    return 0;
}