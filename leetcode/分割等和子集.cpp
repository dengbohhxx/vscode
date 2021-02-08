class Solution {
public:
    int sumvec(vector<int> nums)
    {
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            res+=nums[i];
        }
        return res;
    }
    bool canPartition(vector<int>& nums) {
        int  sum=sumvec(nums);
        if(sum%2==1)
            return false;
        int m=nums.size();
        int n=sum/2;
        vector<vector<bool> > dp(m,vector<bool>(n+1,0));
        for(int i=0;i<m;i++)
        {
            dp[i][0]=false;
        } 
        for(int j=0;j<=n;j++)
        {
            if(nums[0]==j)
            {
                dp[0][j]=true;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j<nums[i])
                {
                    dp[i][j]=dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i]];
                }
            }
        }
        return dp[m-1][n];
    }
};