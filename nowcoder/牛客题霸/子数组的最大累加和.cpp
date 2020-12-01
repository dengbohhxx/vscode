class Solution {
public:
    /**
     * max sum of the subarray
     * @param arr int整型vector the array
     * @return int整型
     */
    int maxsumofSubarray(vector<int>& arr) {
        // write code here
        int size=arr.size();
        vector<int> dp(size);
        dp[0]=arr[0];
        for(int i=1;i<size;i++)
        {
            if(arr[i]<arr[i]+dp[i-1])
                dp[i]=dp[i-1]+arr[i];
            else
                dp[i]=arr[i];
        }
        return *max_element(dp.begin(),dp.end());
    }
};