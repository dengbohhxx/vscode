class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-1]> nums[n-2])
            return n-1;
        int l=0;
        int r=n-1;
        int res=-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
            {
                res=mid;
                break;
            }
            else if(nums[mid]<=nums[mid+1])
            {
                l=mid;
            }
            else if(nums[mid]<=nums[mid-1])
            {
                r=mid;
            }
        }
        return res;
    }
};