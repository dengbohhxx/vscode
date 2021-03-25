class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
            return 1;
        vector<int> dp(11,0);
        dp[0]=1;
        dp[1]=10;
        dp[2]=91;
        for(int i=3;i<=10;i++)
        {
            dp[i]=(dp[i-1]-dp[i-2])*(10-i+1)+dp[i-1];
        }
        if(n<=10)
            return dp[n];
        return dp[10];
        
    }
};