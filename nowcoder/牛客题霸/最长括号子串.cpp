class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        int maxans=0;
        int n=s.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]==')')
            {
                if(s[i-1]=='(')//...()
                {
                    dp[i]=(i>=2?dp[i-2]:0)+2;
                }
                else if(i-dp[i-1]>0&&s[i-dp[i-1]-1]=='(')//...))
                {
                    dp[i]=2+dp[i-1]+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
                }
                maxans=max(maxans,dp[i]);
            }
        }
        return maxans;
    }
};