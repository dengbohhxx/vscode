class Solution {
public:
    int change(int amount, vector<int>& coins) {
            int n=coins.size();
            if(n==0&&amount==0)
                return 1;
            if(n==0)
                return 0;
            vector<vector<int> > dp(n,vector<int>(amount+1,0));
            for(int i=0;i<n;i++)
            {
                dp[i][0]=1;
            }
            for(int j=0;j<amount+1;j++)
            {
                if(j%coins[0]==0)
                    dp[0][j]=1;
                else
                    dp[0][j]=0;
            }
            for(int i=1;i<n;i++)
            {
                for(int j=1;j<amount+1;j++)
                {
                    if(j<coins[i])
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];/
                    }
                }
            }
            return dp[n-1][amount];
    }
};