class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return false;
        int small=INT_MAX;
        int mid=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=small)
            {
                small=nums[i];
            }
            else if(nums[i]<=mid)
            {
                mid=nums[i];
            }
            else 
            {
                return true;
            }
        }
        return false;
    }
};