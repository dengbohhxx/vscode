class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算
     * @param n int整型 数组的长度
     * @param array int整型vector 长度为n的数组
     * @return long长整型
     */
    long long subsequence(int n, vector<int>& array) {
        // write code here
        if(n==0)
            return 0;
        vector<long long> dp(n,0);
        dp[0]=array[0];
        dp[1]=max(array[0],array[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+array[i]);
        }
        return dp[n-1];
    }
};