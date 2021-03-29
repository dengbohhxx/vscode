class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
          if(nums[high] > nums[low]) 
            return nums[low];
        while (low < high) {
            if(nums[high] > nums[low]) 
                return nums[low];
            int mid = low + (high - low) / 2;
            if(nums[low]<nums[mid])
            {
                low=mid+1;
            }
            else if(nums[low]>nums[mid])
            {
                high=mid;
            }
            else
            {
                low++;
            }
        }
        return nums[low];
    }
};