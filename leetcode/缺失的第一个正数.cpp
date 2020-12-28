class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
            //最小正整数只能在 [1,N+1] 中
        int n=nums.size();
        for(int i=0;i<n;i++)//将数组中负数转化为n+1
        {
            if(nums[i]<=0)
            {
                nums[i]=n+1;
            }
        }
        //将小于n位置的数字打标机，记为负数
        for(int i=0;i<n;i++)
        {
            int num=abs(nums[i]);
            if(num<=n)
            {
                nums[num-1]=-1*abs(nums[num-1]);
            }
        }
        //第一个未标记（正数）的位置i+1即为数组中未出现的最小正整数
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                return i+1;
        }
        
        return n+1;
    }
};