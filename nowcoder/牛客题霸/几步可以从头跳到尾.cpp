class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 最少需要跳跃几次能跳到末尾
     * @param n int整型 数组A的长度
     * @param A int整型vector 数组A
     * @return int整型
    int Jump(int n, vector<int>& A) {//时间复杂度O(n*n)超时
    
        // write code here
        if(n==0)
            return 0;
        vector<int> dp(n,INT_MAX);//dp[i] 为到i位置时最少的步数
        dp[0]=0;
        for(int i=1;i<n;++i)
        {
            
            for(int j=0;j<i;++j)
            {
                if(j+A[j]>=i)
                    dp[i]=min(dp[i],dp[j]+1);
            }
        }
        return dp[n-1];
    }
};
     */
     int Jump(int n, vector<int>& A) {
        // write code here
       int right=0;
       int step=0;
       int maxpos=0;
       for(int i=0;i<n-1;i++)
       {
           if(maxpos>=i)
           {
               maxpos=max(maxpos,A[i]+i);//更新最远到达
               if(right==i)
               {
                   step++;
                   right=maxpos;
               }
           }
       }
        return step;   
    }
};