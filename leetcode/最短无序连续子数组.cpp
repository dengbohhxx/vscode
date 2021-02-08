class Solution {
public:
    /*
    从左到右维护一个最大值max,在进入右段之前，那么遍历到的nums[i]都是小于max的，我们要求的end就是遍历中最后一个小于max元素的位置；
同理，从右到左维护一个最小值min，在进入左段之前，那么遍历到的nums[i]也都是大于min的，要求的begin也就是最后一个大于min元素的位置。
    */
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int max=INT_MIN;
        int min=INT_MAX;
        int p=0;
        int q=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>=max)
            {
                max=nums[i];
            }
            else
            {
                p=i;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]<=min)
            {
                min=nums[i];
            }
            else
            {
                q=i;
            }
        }
        if(p==q)
            return 0;
        return p-q+1;
    }
};