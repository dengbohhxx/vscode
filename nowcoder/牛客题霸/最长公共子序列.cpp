#include<iostream>
#include<string>
#include<vector>
#include<limits.h>
using namespace std;
string LCS(string s1, string s2) {
        // write code here
        int m=s1.size();
        int n=s2.size();
        vector<vector<string> > dp(m,vector<string>(n));
        for(int i=0;i<m;i++)
        {
            if(s1[i]==s2[0])
                dp[i][0]=s1[i];
        }
        for(int i=0;i<n;i++)
        {
            if(s1[0]==s2[i])
                dp[0][i]=s1[0];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j]=dp[i-1][j-1]+s1[i];
                }
                else
                {
                    int size1=dp[i-1][j].size();
                    int size2=dp[i][j-1].size();
                    if(size1<=size2)
                        dp[i][j]=dp[i][j-1];
                    else
                        dp[i][j]=dp[i-1][j];
                }
            }
        }
        int max=0;
        string str;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j].size()>max)
                {
                    max=dp[i][j].size();
                    str=dp[i][j];
                }
            }
        }
        if(str.empty())
        return "-1";
         return str;   
    }
int main()
{
    string str1="12345";
    string str2="B1D23CA45B6A";
    string str=LCS(str1,str2);
    cout<<str<<endl;




    return 0;
}