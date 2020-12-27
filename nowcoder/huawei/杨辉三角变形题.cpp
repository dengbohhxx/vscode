#include<iostream>
#include<vector>
using namespace std;
int find(int n)
{
    int row=n;
    int col=2*n-1;
    vector<vector<int> > dp(row,vector<int>(col,0));
    dp[0][row-1]=1;
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col-1;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
        }
    }
    dp[row-1][0]=1;
    dp[row-1][col-1]=1;
    int i=0;
    for(i=0;i<col;i++)
    {
        if(dp[row-1][i]!=0&&dp[row-1][i]%2==0)
            break;
    }
    if(i==col)
        return -1;
    else
        return i+1;
}
int main()
{
    int n=0;
    while(cin>>n)
    {
        int res=find(n);
        cout<<res<<endl;
    }
    
    return 0;
}