class Solution {
public:
    /**
     * 解码
     * @param nums string字符串 数字串
     * @return int整型
     */
    int solve(string nums) {
        // write code here
        int n=nums.size();
        if(n==0||nums=="0")
            return 0;
        vector<int> dp(n);
        dp[0]=1;
        dp[1]=(((nums[0]-'0')*10+nums[1]-'0')<=26&&((nums[0]-'0')*10+nums[1]-'0')>10)?2:1;
        for(int i=2;i<n;i++)
        {
            int t=(nums[i-1]-'0')*10+(nums[i]-'0');
            if(t>=10&&t<=26&&t!=20&&t!=10)
                dp[i]=dp[i-1]+dp[i-2];
            else
            {
                if(nums[i]-'0'==0&&(nums[i-1]-'0'==0))
                    return 0;
                if((nums[i-1]-'0')>=3&&nums[i]-'0'==0)
                    return 0;
                dp[i]=dp[i-1];
            }
        }
        return dp[n-1];
    }
};