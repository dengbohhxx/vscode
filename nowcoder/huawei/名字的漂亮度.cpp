#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int countbu(string s)
{
    vector<int> vec(26);
    int k=s.size();
    for(int i=0;i<k;i++)
    {
        vec[tolower(s[i])-'a']++;
    }
    int sum=0;
    int score=26;
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    for(int i=0;i<vec.size();i++)
    {
        sum+=vec[i]*score;
        score--;
    }
    return sum;
}
int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> vec;
        while(n--)
        {
            string s;
            cin>>s;
            vec.push_back(s);
        }
        for(int i=0;i<vec.size();i++)
        {
            cout<<countbu(vec[i])<<endl;
        }
    }
    return 0;
}