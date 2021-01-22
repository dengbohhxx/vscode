class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string 一个字符串由小写字母构成，长度小于5000
     * @return int
     */
    int longestPalindromeSubSeq(string s) {
        // write code here
        int n=s.size();
        vector<vector<int> >dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};