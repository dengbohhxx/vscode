class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0)
            return 0;
        vector<vector<int> > dp(n,vector<int>(n,INT_MAX));
        int temp=0;
        for(int i=0;i<n;i++)
        {
            temp+=triangle[i][0];
            dp[i][0]=temp;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
            }
        }
        return *min_element(dp[n-1].begin(),dp[n-1].end());
    }
};