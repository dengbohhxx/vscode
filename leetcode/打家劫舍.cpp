class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        dp[0]=nums[0];
        dp[1]=nums[1];
        //int max1=0;
        for(int i=2;i<n;i++)
        {
            int max1=0;
            for(int j=0;j<i-1;j++)
            {
                dp[i]=max(max1,dp[j])+nums[i];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};