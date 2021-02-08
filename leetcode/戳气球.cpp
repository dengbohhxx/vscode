class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> point(n+2);
        point[0]=point[n+1]=1;
        for(int i=1;i<=n;i++)
        {
            point[i]=nums[i-1];
        }
        vector<vector<int> >dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=0;i--)
        {
            for(int j=i+1;j<=n+1;j++)
            {
                for(int k=i+1;k<j;k++)
                    dp[i][j]=max(dp[i][j],dp[i][k]+dp[k][j]+point[i]*point[j]*point[k]);
            }
        }
        return dp[0][n+1];
    }
};