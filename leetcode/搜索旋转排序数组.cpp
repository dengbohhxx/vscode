class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
            return -1;
        if(n==1)
            return nums[0]==target?0:-1; 
        int  l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[0]<=nums[mid])//有序 等于号是有可能只有一个元素
            {
                if(nums[0]<=target&&target<nums[mid])
                {
                    r=mid-1;
                }
                else
                {
                    l=mid+1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])//有序
                 {
                     l=mid+1;
                 }
                 else
                 {
                     r=mid-1;
                 }
            }
        }
        return -1;
    }
};