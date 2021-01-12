class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        vector<vector<int> > dp(n,vector<int>(2,0));
        dp[0][0]=0;
        dp[0][1]=-prices[0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//第i天不持有股票
            dp[i][1]=max(dp[i-1][1],-prices[i]);//第i天持有股票 最多只允许完成一笔交易
        }
        return dp[n-1][0];
    }
};
class Solution {
public:
    /**
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int size=prices.size();
        int m=0;
        for(int i=1;i<size;i++)
        {
            
            for(int j=0;j<i;j++)
            {
                if(prices[i]>prices[j])
                {
                    int profit=prices[i]-prices[j];
                    m=max(m,profit);
                }
            }
        }
        return m;
    }
};