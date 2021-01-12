class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        int num=0;
        for(int d=0;d<n;d++)
        {
            for(int i=0;i<n-d;i++)
            {
                int j=i+d;
                if(s[i]==s[j])
                {
                    if(d==0||d==1)
                        dp[i][j]=true;
                    else
                    {
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]==true)
                {
                    num++;
                }
            }
        }
        return num;
    }
};