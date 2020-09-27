class Exchange {
public:
    int countWays(vector<int> penny, int n, int aim) {
       
        //当penny为空或者目标为0直接返回
        if (penny.empty() || aim == 0)  
            return 0;
        return foo(penny, 0, aim);
    }
    int foo(const vector<int>& arr, int n, int aim)
    {
        //边界条件
       if (aim==0)
           return 1;
        //边界条件
        if(n==arr.size())
            return 0;
        int  res=0;
        for(int i=0;arr[n]*i<=aim;i++)
            res+=foo(arr,n+1,aim-arr[n]*i);
        return res;
    }
        //创建动态数组
        vector<vector<int> > dp(n,vector<int>(aim+1));
        //初始化第一列
        for(int i=0;i<n;i++)
            dp[i][0]=1;
        //初始化第一行
        for(int i=0;i<aim+1;i++)
        {
            if(i%penny[0]==0)
                dp[0][i]=1;
            else
                dp[0][i]=0;
        }
        //填充动态数组
        for(int i=1;i<n;i++)//第一行和第一列已经赋值过，所以ij均从下标1开始
        {
            for(int j=1;j<aim+1;j++)
            {
                if(j<penny[i])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i][j-penny[i]];//状态转移方程
            }
           
        }
         return dp[n-1][aim];
    }
};