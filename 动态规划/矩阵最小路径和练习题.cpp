class MinimumPath {
public:
	int getMin(vector<vector<int> > map, int n, int m) {
		// write code here
		//初始化dp
        vector<vector<int> > dp(n, vector<int>(m));
        
        dp[0][0]=map[0][0];
        //初始化第一行
		for (int i = 1; i<m; i++)
			dp[0][i] = dp[0][i-1]+map[0][i];
        //初始化第一列
		for (int i = 1; i<n; i++)
			dp[i][0] = dp[i-1][0]+map[i][0];
        
		for (int i = 1; i<n; i++)
		{
			for (int j = 1; j<m; j++)
			{
				dp[i][j] = map[i][j] + min(dp[i-1][j],dp[i][j-1]);//状态转移方程

			}
		}
		return dp[n - 1][m - 1];
	}
};