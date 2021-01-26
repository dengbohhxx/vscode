class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        if(n==0||amount==0) 
            return 0;
        //sort(coins.begin(),coins.end());
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<dp.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(coins[j]<=i)
                {
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount]==amount+1)?-1:dp[amount];
    }
};