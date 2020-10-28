#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        
        vector<int> vec(256);
        int size=str.size();
        for(int i=0;i<size;i++)
        {
            vec[str[i]-NULL]++;
        }
        int k=-1;
        for(int i=0;i<size;i++)
        {
            if(vec[str[i]-NULL]==1)
            {
                cout<<str[i];
                k++;
                break;
            }
        }
        if(k==-1)
            cout<<k;
        cout<<endl;
        
    }
    return 0;
}