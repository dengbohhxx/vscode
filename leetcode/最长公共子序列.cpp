class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        if(m==0||n==0)
            return 0;
        vector<vector<int> > dp(m,vector<int>(n,0));
        int a=0;
        for(int i=0;i<m;i++)
        {
            if(text1[i]==text2[0])
            {
                a=1;
            }
            dp[i][0]=a;
        }
        a=0;
        for(int j=0;j<n;j++)
        {
            if(text1[0]==text2[j])
            {
                a=1;
            }
            dp[0][j]=a;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(text1[i]==text2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};