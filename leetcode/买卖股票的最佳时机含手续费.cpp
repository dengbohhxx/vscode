class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        if(n==0)
            return 0;
        vector<vector<int> > dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);//第i天不持有股票
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//第i天持有股票
        }
        return dp[n-1][0];
    }
};