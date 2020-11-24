class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size()==1)
            return array[0];
        int size=array.size();
        vector<int> dp(size);
        dp[0]=array[0];
        for(int i=1;i<size;i++)
        {
            if(dp[i-1]+array[i]<array[i])
                dp[i]=array[i];
            else
            {
                dp[i]=dp[i-1]+array[i];
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};