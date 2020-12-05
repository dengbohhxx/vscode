class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        int m=0;
        for(int d=0;d<n;d++)
        {
            for(int i=0;i<n-d;i++)
            {
                int j=i+d;
                if(A[i]==A[j])
                {
                    if(d==0||d==1)
                        dp[i][j]=true;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true)
                    m=max(m,d+1);
            }
        }
        return m;
    }
};