class Solution {
public:
    /**
     * min edit cost
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @param ic int整型 insert cost
     * @param dc int整型 delete cost
     * @param rc int整型 replace cost
     * @return int整型
     */
    int minEditCost(string str1, string str2, int ic, int dc, int rc) {
        // write code here
        int m=str1.size();
        int n=str2.size();
        vector<vector<int> > dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<m+1;i++)
        {
            dp[i][0]=i*dc;
        }
        for(int i=0;i<n+1;i++)
        {
            dp[0][i]=i*ic;
        }
        for(int i=1;i<m+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=min(min(dp[i-1][j]+dc,dp[i][j-1]+ic),dp[i-1][j-1]+rc);
                }
            }
        }
        return dp[m][n];
    }
};