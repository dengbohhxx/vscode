#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
        int m=str1.size();
        int n=str2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=i;
        }
        for(int j=0;j<n+1;j++)
        {
            dp[0][j]=j;
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=min(min(dp[i-1][j]+1,dp[i][j-1]+1),str1[i-1]==str2[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+1);
            }
        }
        cout<<"1/"<<to_string(dp[m][n]+1)<<endl;
    }
    return 0;
}
