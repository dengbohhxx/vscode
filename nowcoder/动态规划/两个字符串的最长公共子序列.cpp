class LCS {
public:
    int findLCS(string A, int n, string B, int m) {
        // write code here
        vector<vector<int> > dp(n,vector<int>(m));
        int a=0;
        //第一列
        for(int i=0;i<n;i++)
        {
            if(A[i]==B[0])
              a=1;
            dp[i][0]=a;
        }
        a=0;
        //第一行
        for(int i=0;i<m;i++)
        {
            if(B[i]==A[0])
             a=1;
            dp[0][i]=a;
        }
        //
        for(int i=1;i<n;i++)
        {
            for(int  j=1;j<m;j++)
            {//状态转移方程
                if(A[i]!=B[j])
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                else
                    dp[i][j]=dp[i-1][j-1]+1;
            }
        }
        return dp[n-1][m-1];
    }
};