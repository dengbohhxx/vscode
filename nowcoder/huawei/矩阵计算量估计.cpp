#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
int main()
{
    int num = 0;
    while(cin>>num)
    {
        vector<vector<int> > vec(num);
        int m,n;
        for(int i=0;i<num;i++)
        {
            cin>>m>>n;
            vec[i].push_back(m);
            vec[i].push_back(n);
        }
        string str;
        cin>>str;
        int sum=0;
        stack<int> sta;
        for(int i=str.size()-2;i>=1;i--)
        {
            if(str[i]!='(')
                sta.push(str[i]);
            else
            {
                while()
            }
            
        }







    }
    return 0;
}