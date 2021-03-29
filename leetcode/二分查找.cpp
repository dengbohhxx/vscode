class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
           return -1;
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
            {
                r=mid-1;
            }
            else if(nums[mid]>target)
            {
                r=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
        }
        if(l>=n||nums[l]!=target)
        {
            return -1;
        }
        return l;
    }
};