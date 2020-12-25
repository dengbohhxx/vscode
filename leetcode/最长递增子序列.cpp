class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
           //O(nlogn) 贪心+二分  dp[i] 表示长度为 ii 的最长上升子序列的末尾元素的最小值,dp[i]是单调递增的，寻找位置i时用二分
            int n=nums.size();
            int len=1;
            vector<int> dp(n+1,0);
            dp[1]=nums[0];
            for(int i=1;i<n;i++)
            {
                if(dp[len]<nums[i])
                {
                    len++;
                    dp[len]=nums[i];
                }
                else
                {
                    int l=1;
                    int r=len;
                    int pos=0;
                    while(l<=r)
                    {
                        int mid=(l+r)/2;
                        if(dp[mid]<nums[i])
                        {
                            pos=mid;
                            l=mid+1;
                        }
                        else
                        {
                            r=mid-1;
                        }
                    }
                     dp[pos+1]=nums[i];
                }
            }
        return len;    
    }
};