class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<bool> > dp(m+1,vector<bool>(n+1,false));
        dp[0][0]=true;
        for(int j=2;j<=n;j++)
        {
            dp[0][j]=p[j-1]=='*'&&dp[0][j-2];//再往后 dp[0][2]，p[1] = '*'，它可以选择消除掉第一个字符a，那么这个子串就也变成了一个空串，因此是匹配的。再往后推，dp[0][3]为 false，dp[i][4] 因//                                                                                //为 p[3]是 '*' 所以可以消除掉前面的b，同时第一个 '*' 可以消除掉 a，所以整体p又变成了一个空串，是匹配的。
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==p[j-1]||p[j-1]=='.')//s[i-1] == p[j-1]
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                    if(j>1&&s[i-1]!=p[j-2]&&p[j-2]!='.')//p[j-2] != s[i-1]
                    {
                        dp[i][j]=dp[i][j-2];
                    }
                    else//p[j-2] = s[i-1]
                    {
                        dp[i][j]=dp[i][j-2]||dp[i][j-1]||dp[i-1][j];//1. s = 'abc', p = "abcc*";  
                                                                                                     //2. s = "abc", p = "abc*";
                                                                                                     //3.  s = "abcc" or "abccc" or "abcccc..", p = "abc*"
                    }
                }
            }
        }
        return dp[m][n];
    }
};