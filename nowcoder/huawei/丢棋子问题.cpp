/*
class Solution {
public:
    int solve(int N, int K) {
        // write code here
        if(N<1||K<1)
            return 0;
        if(K==1)
            return N;
        vector<vector<int> > dp(N+1,vector<int>(K));
        for(int j=0;j<=K;j++)
        {
            dp[0][j]=0;
        }
        dp[1][0]=0;
        for(int j=1;j<=K;j++)
        {
            dp[1][j]=1;
        }
        for(int i=0;i<=N;i++)
        {
            dp[i][0]=0;
            dp[i][1]=i;
        }
        for(int i=2;i<=N;i++)
        {
            for(int j=2;j<=K;j++)
            {
                int min1=INT_MAX;
                for(int k=1;k<=i;k++)
                {
                    min1=min(min1,max(dp[k-1][j-1],dp[i-k][j]));
                }
                dp[i][j]=min1+1;
            }
        }
        return dp[N][K];
    }
};
    int help(int n,int k)
    {
        if(n==0)
            return 0;
        if(k==1)
            return n;
        int min1=INT_MAX;
        for(int i=1;i<=n;i++)
            min1=min(min1,max(help(i-1,k-1),help(n-i,k)));
        return min1+1;
    }
    int solve(int n, int k) {
        // write code here
           if(n<1||k<1)
               return 0;
        return help(n,k);
    }
*/
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 返回最差情况下扔棋子的最小次数
     * @param n int整型 楼层数
     * @param k int整型 棋子数
     * @return int整型
     */

    int solve(int n, int k) {
        // write code here
        if(n < 1)
            return 0;
        if(k == 1)
            return n;
         
        int logtimes = log2(n) + 1;
        if( k >= logtimes)
            return logtimes;
         
        vector<int>f(k+1,0);
        int cnt=0;
         
        while(f[k] < n)
        {
            ++cnt;
            for(int i = k;i > 0;--i)
                f[i] += f[i-1] + 1;
        }
        return cnt;
        
    }
};