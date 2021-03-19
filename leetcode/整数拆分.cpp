class Solution {
public:
    int integerBreak(int n) {
        if(n==0||n==1)
            return 0;
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            int l=1;
            int r=i-1;
            int res=INT_MIN;
            while(l<=r)
            {
                int temp1=max(l,dp[l]);
                int temp2=max(r,dp[r]);
                res=max(res,temp1*temp2);
                l++;
                r--;
            }
            dp[i]=res;
        }
        return dp[n];
    }
};