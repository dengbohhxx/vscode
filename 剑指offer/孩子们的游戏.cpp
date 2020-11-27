#include<iostream>
#include<list>
using namespace std;
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        list<int> li;
        for(int i=0;i<n;i++)
        {
            li.push_back(i);
        }
        list<int>::iterator iter=li.begin();
        while(li.size()>1)
        {
            for(int i=1;i<=m-1;i++)
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
int main()
{
    int  n=LastRemaining_Solution(5,3);
    cout<<n<<endl;
}