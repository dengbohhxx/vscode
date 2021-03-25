class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size();
        int n=B.size();
        if(m==0||n==0)
            return 0;
        vector<vector<int> > dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            if(A[i]==B[0])
                {
                    dp[i][0]=1;
                }
        }
        for(int j=0;j<n;j++)
        {
            if(A[0]==B[j])
            {
                dp[0][j]=1;
            }
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(A[i]==B[j])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
            }
        }
        int max1=INT_MIN;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                max1=max(max1,dp[i][j]);
            }
        }
        return max1;

    }
};