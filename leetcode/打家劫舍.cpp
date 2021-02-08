/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        vector<int> dp(n,0);//以i结尾的最高偷盗金额
        dp[0]=nums[0];
        dp[1]=nums[1];
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
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> dp(n,0);//用 dp[i]dp[i] 表示前 ii 间房屋能偷窃到的最高总金额
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+nums[i]);
        } 
        return dp[n-1];
    }
};