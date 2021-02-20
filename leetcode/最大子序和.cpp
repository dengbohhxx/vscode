class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            if(dp[i-1]+nums[i]<=nums[i])
            {
                dp[i]=nums[i];
            }
            else
            {
                dp[i]=dp[i-1]+nums[i];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};