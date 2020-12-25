#include<iostream>
#include<string>
#include<vector>
#include<algorithm>  
using namespace std;
bool bro(string str1,string str2)
{
    vector<int> arr(26,0);
    if(str1.size()!=str2.size())
        return false;
    if(str1==str2)
        return false;
    int n=str1.size();
    for(int i=0;i<n;i++)
        {
            arr[str1[i]-'a']++;
            arr[str2[i]-'a']--;
        }
    for(int i=0;i<26;i++)
       {
           if(arr[i]!=0)
                    return false;
       }
    return true;
}
vector<string> findbro(vector<string> vec,string str)
{
    vector<string> res;
    for(int i=0;i<vec.size();i++)
    {
        if(bro(vec[i],str))
            res.push_back(vec[i]);
    }
    sort(res.begin(),res.end());
    return res;
}
int main()
{
    int n=0;
    while(cin>>n)
    {
        string s;
        vector<string> vec;
        while(n--)
        {
            cin>>s;
            vec.push_back(s);
        }
        string str;
        int k=0;
        cin>>str;
        cin>>k;
        auto res=findbro(vec,str);
        cout<<res.size()<<endl;
        if(k<=res.size())
        {
            string s1=res[k-1];
            cout<<s1<<endl;;
        }
    }
    return 0;
}