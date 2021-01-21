class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<vector<int> > dp(n,vector<int>(V+1,0));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=0;
        }
        int a=0;
        for(int j=0;j<V+1;j++)
        {
            if(j>=vw[0][0])
                a=vw[0][1];
            dp[0][j]=a;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<V+1;j++)
            {
                if(j<vw[i][0])
                    dp[i][j]=dp[i-1][j];
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i-1][j-vw[i][0]]+vw[i][1]);
                }
            }
        }
        return dp[n-1][V];
    }
};