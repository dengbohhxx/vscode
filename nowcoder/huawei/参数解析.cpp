#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str;
    while(getline(cin,str))
    {
        string s;
        vector<string> vec;
        int flag=0;
        str=str+' ';
        for(int i=0;i<str.size();i++)
        {
            if((flag==0&&str[i]!=' ')||flag!=0 &&str[i]==' ')
            {
                if(str[i]=='"')
                {
                    flag++;
                }
                else
                {
                    s+=str[i];
                }
            }
            else
            {
                vec.push_back(s);
                s.clear();
                flag==0;
            }
                    
        }
        cout<<vec.size()<<endl;
        for(int i=0;i<vec.size();i++)
        {
            cout<<vec[i]<<endl;
        }
    }
    return 0;
}