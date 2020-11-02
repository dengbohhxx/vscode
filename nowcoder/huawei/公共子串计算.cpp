#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;
int main()
{
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int> > dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(tolower(str1[i])==tolower(str2[0]))
                dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(tolower(str1[0])==tolower(str2[i]))
                dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(tolower(str1[i])==tolower(str2[j]))
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
            }
        }
        int max=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(max<=dp[i][j])
                    max=dp[i][j];
            }
        }
       cout<<max<<endl;
    }
    return 0;
}