class Backpack {
public:
    int maxValue(vector<int> w, vector<int> v, int n, int cap) {
        // write code here
        vector<vector<int> > dp(n,vector<int>(cap+1));
        int a=0;
        //初始化第一行
        for(int i=0;i<cap+1;i++)
        {
            if(i>=w[0])
             a=v[0];
            dp[0][i]=a;
        }
        //初始化第一列
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        //状态转移
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<cap+1;j++)
            {
                if(j>=w[i])//如果承载能力j大于w[i]
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
                else//如果承载能力小于w[i]，那么dp[i][j]=dp[i-1][j]
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][cap];
    }
};