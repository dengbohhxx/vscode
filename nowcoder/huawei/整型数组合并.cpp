#include<set>
#include<algorithm>
using namespace std;
int main()
{
    int m=0;
    int x=0;
    while(cin>>m)
    {
        set<int> s;
        while(m--)
        {
            cin>>x;
            s.insert(x);
        }
        int n=0;
        cin>>n;
        while(n--)
        {
            cin>>x;
            s.insert(x);
        }
        //sort(s.begin(),s.end());
        for(set<int>::iterator iter=s.begin();iter!=s.end();iter++)
        {
            cout<<*iter;
        }
        cout<<endl;
    }
    return 0;
}