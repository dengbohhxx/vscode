class Solution {
public:
    /**
     * 
     * @param grid int整型vector<vector<>> 
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& grid) {
        // write code here
        int m=grid.size();
        int n=grid[0].size();
        if(m==0||n==0)
            return 0;
        vector<vector<int> > dp(m,vector<int>(n,0));
        int sum=0;
        for(int i=0;i<m;i++)
        {
            sum+=grid[i][0];
            dp[i][0]=sum;
        }
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=grid[0][j];
            dp[0][j]=sum;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};