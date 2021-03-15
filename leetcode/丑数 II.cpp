class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n,0);
        dp[0]=1;
        int ugly=0;
        int i2=0;
        int i3=0;
        int i5=0;
        for(int i=1;i<n;i++)
        {
            ugly=min(min(dp[i2]*2,dp[i3]*3),dp[i5]*5);
            dp[i]=ugly;
            if(ugly==dp[i2]*2)
                i2++;
            if(ugly==dp[i3]*3)
                i3++;
            if(ugly==dp[i5]*5)
                i5++;
        }
        
        return dp[n-1];
    }
};