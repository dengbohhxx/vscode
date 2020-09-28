class MinCost {
public:
    int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
        // write code here
        vector<vector<int> > dp(n+1,vector<int>(m+1));
        for(int i=0;i<m+1;i++)
        {
            dp[0][i]=i*c0;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[i][0]=i*c1;
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                dp[i][j]=min(min(dp[i-1][j]+c1,dp[i][j-1]+c0),A[i-1]==B[j-1]?dp[i-1][j-1]:dp[i-1][j-1]+c2);//因为dp都为n+1,m+1维，前面都加了0，因此判断A,B是否相等时需要减一
            }
        }
        return dp[n][m];
    }
};