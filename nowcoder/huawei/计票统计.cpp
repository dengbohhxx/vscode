#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    int n=0;
    while(cin>>n)
    {
        vector<string> vec;
        string c;
        while(n--)
        {
            cin>>c;
            vec.push_back(c);
        }
        int m=0;
        cin>>m;
        vector<string> vec1;
        while(m--)
        {
            cin>>c;
            vec1.push_back(c);
        }
        int k2=vec1.size();
        for(int i=0;i<vec.size();i++)
        {
            int k1=0;
            for(int j=0;j<vec1.size();j++)
            {
                if(vec[i]==vec1[j])
                    k1++;
            }
            cout<<vec[i]<<" : "<<k1<<endl;
            k2=k2-k1;
        }
        cout<<"Invalid"<<" : "<<k2<<endl;
    }
    return 0;
}