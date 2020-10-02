#include<iostream>
#include<string>
#include<vector>
using namespace std;
int  calStringDistance (string charA, string  charB)
{
    int m=charA.size();
    int n=charB.size();
    vector<vector<int> > dp(m+1,vector<int>(n+1));
    for(int i=1;i<m+1;i++)
    {
        dp[i][0]=i;
    }
    for(int j=1;j<n+1;j++)
    {
        dp[0][j]=j;
    }
    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(charA[i-1]==charB[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
            {
                dp[i][j]=min(dp[i-1][j-1]+1,min(dp[i-1][j]+1,dp[i][j-1]+1));
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)
    {
        int distance=calStringDistance(str1,str2);
        cout<<distance<<endl;
    }
    return 0;
}