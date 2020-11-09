#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool match(string str1,string str2)
{
    if(str2.find(str1)==0)
        return true;
    else
        return false;
}
vector<string> str2vec(string str)
{
    str+=' ';
    string s;
    vector<string> vec;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]!=' ')
            s+=str[i];
        else
        {
            vec.push_back(s);
            s.clear();
        }
    }
    return vec;
}
string cmd[6] = {"reset","reset board","board add","board delete","reboot backplane","backplane abort"};
string res[7] = {"reset what","board fault","where to add","no board at all","impossible","install first","unknown command"};
int main()
{
    string str;
    while(getline(cin,str))
    {
        vector<string> vec=str2vec(str);
        if(vec.size()==1)
        {
            if(match(vec[0],cmd[0]))
                cout<<res[0]<<endl;
            else
                cout<<res[6]<<endl;
        }
        else if(vec.size()==2)
        {
            int k=0;
            int index=0;
            for(int i=1;i<=5;i++)
            {
                vector<string> vec1=str2vec(cmd[i]);
                if(match(vec[0],vec1[0])&&match(vec[1],vec1[1]))
                {
                    k++;
                    index=i;
                }
            }
            if(k==1)
            {
                cout<<res[index]<<endl;
            }
            else
            {
                cout<<res[6]<<endl;
            }
        }
        
    }
    return 0;
}