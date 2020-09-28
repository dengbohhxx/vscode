class LongestIncreasingSubsequence {
public:
    int getLIS(vector<int> A, int n) {
        /*
        vector<int> dp(n);
	dp[0] = 1;
        //以dp[i]结尾，找到所有小于A[i]的A，其中dp最大的+1返回
	for (int i = 1; i < n; i++)
	{
		
		for (int j = 0; j < i; j++)
		{
			if (A[i]>A[j])
				dp[i] = max(dp[i], dp[j]);
			
		}
		dp[i] += 1;
	}
        //dp中最大的返回
	return *max_element(dp.begin(), dp.end());
    */
        vector<int> dp(n);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(A[i]>A[j])
                 dp[i]=max(dp[i],dp[j]);
            }    
            dp[i]++;
        }
        return *max_element(dp.begin(),dp.end());
    }
};