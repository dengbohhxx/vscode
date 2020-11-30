class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int m=str1.size();
        int n=str2.size();
        if(m==0||n==0)
            return "-1";
        vector<vector<int> > dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            if(str1[0]==str2[i])
                dp[0][i]=1;
        }
        for(int i=0;i<m;i++)
        {
            if(str1[i]==str2[0])
                dp[i][0]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(str1[i]==str2[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
            }
        }
        int len=INT_MIN;
        int k=-1;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dp[i][j]>len)
                {
                    len=dp[i][j];
                    k=i;
                }
            }
        }
        if(len==0)
            return "-1";
        string str(str1.begin()+k-len+1,str1.begin()+k+1);
        return str;
    }
};