class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        vector<vector<int> > d(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            d[i][i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1)
                        d[i][j]=1;
                    else
                        d[i][j]=d[i+1][j-1];
                }
            }
        }
        vector<int> dp(n, INT_MAX);
        for(int i=0;i<n;i++)
        {
            if(d[0][i])
            {
                dp[i]=0;
            }
            else
            {
                for(int j=0;j<i;j++)
                {
                    if(d[j+1][i]==1)
                    {
                        dp[i]=min(dp[i],dp[j]+1);
                    }
                }
            }
        }
        return dp[n-1];
    }
};