#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int n=0;
        cin>>n;
        int size=s.size();
        string temp="";
        for(int i=0;i<size;i++)
        {
            if(s[i]-NULL>=0&&s[i]-NULL<=255)
            {
                n=n-1;
                if(n<0)
                    break;
                temp+=s[i];
            }
            else
            {
                n=n-2;
                if(n<0)
                    break;
                temp+=s[i];
            }
        }
        cout<<temp<<endl;
    }
    return 0;
}