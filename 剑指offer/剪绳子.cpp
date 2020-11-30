class Solution {
public:
    int cutRope(int number) {
        if(number==2)
            return 1;
        if(number==3)
            return 2;
        vector<int> dp(number+1,-1);
        for(int i=1;i<4;i++)
            dp[i]=i;
        for(int i=5;i<=number;i++)
        {
            int max=0;
            for(int j=1;j<i;j++)
            {
                int dot=dp[j]*dp[i-j];
                if(dot>max)
                    max=dot;
                dp[i]=max;
            }
        }
        return dp[number];
    }
};