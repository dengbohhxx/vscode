#include<iostream>
#include<string>
#include<vector>
using namespace std;
int getLongestPalindrome(string A, int n) 
{
    vector<vector<bool> > dp(n,vector<bool>(n,false));
    int m=0;
    for(int d=0;d<n;d++)
    {
        for(int i=0;i<n-d;i++)
        {
            int j=i+d;
            if(A[i]==A[j])
            {
                if(d==0||d==1)
                    dp[i][j]=true;
                else
                    dp[i][j]=dp[i+1][j-1];
            }
            if(dp[i][j]==true)
                m=max(m,d+1);
        }
    }
    return m;
}
int main()
{
    string s;
    while(cin>>s)
    {
        int n=s.size();
        int res=getLongestPalindrome(s,n);
        cout<<res<<endl;
    }
    
    
    
    return 0;
}