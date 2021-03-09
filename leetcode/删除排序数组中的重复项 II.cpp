class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        int slow=0;
        int k=0;
        for(int fast=1;fast<n;fast++)
        {
            if(nums[slow]==nums[fast])
            {
                k++;
                 if(k==1)
                {
                    slow++;
                    nums[slow]=nums[fast];
                }
            }
            if(nums[slow]!=nums[fast])
            {
                slow++;
                nums[slow]=nums[fast];
                k=0;
            }
        }
        return slow+1;
    }
};