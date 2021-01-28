class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0||n==0)
            return 0;
        vector<vector<int> >dp(m,vector<int>(n,0));
        /*
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]=='1')
                dp[i][0]=1;
        }
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]=='1')
                dp[0][i]=1;
        }
        */
        int maxlen=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    if(i==0||j==0)
                    {
                        dp[i][j]=1;
                    }
                    else
                    {
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;//dp[i][j]的值取决于dp[i-1][j],dp[i-1][j-1],dp[i][j-1]的最小值
                                                                            //即左方正方形的边长，左上方正方形的边长，上方正方形的边长三者的最小值。
                    }
                    maxlen=max(maxlen,dp[i][j]);
                }
            }
        }
        return pow(maxlen,2);
    }
};