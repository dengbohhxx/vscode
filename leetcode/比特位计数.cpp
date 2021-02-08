class Solution {
public:
    vector<int> countBits(int num) {
        //利用 n & (n-1) 可以去除 n（实际是比特位）中最后的一位1,得到一个新的数, 此时,这个数肯定小于n ,它已被我们求出。根据动态规划的原理，直接用即可
        vector<int> dp(num+1,0);
        for(int i=1;i<=num;i++)
        {
            dp[i]=dp[i&(i-1)]+1;
        }
        return dp;
    }
};