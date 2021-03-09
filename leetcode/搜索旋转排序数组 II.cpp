class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
            return false;
        if(n==1)
            return nums[0]==target?true:false; 
        int  l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]==target)
                return true;
                if (nums[l] == nums[mid])
                 {
                    l++;
                    continue;
                 }
            if(nums[l]<=nums[mid])//有序 等于号是有可能只有一个元素
            { 
                if(nums[l]<=target&&target<nums[mid])
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
                if (nums[mid] < target && target <= nums[r])//有序
                 {
                     l=mid+1;
                 }
                 else
                 {
                     r=mid-1;
                 }
            }
        }
        return false;
    }
};