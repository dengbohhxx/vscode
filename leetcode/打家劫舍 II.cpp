class Solution {
public:
     int rob1(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> vec1(nums.begin()+1,nums.end());
        int max1=rob1(vec1);
        vector<int> vec2(nums.begin(),nums.end()-1);
        int max2=rob1(vec2);
        return max(max1,max2);
    }
};