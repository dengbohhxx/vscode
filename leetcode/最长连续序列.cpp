class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return 1;
        sort(nums.begin(),nums.end());

        int max1=INT_MIN;
        int len=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-1==nums[i-1])
                len++;
            else if(nums[i]!=nums[i-1])
            {
                len=1;
            }
            max1=max(len,max1);
        
        }
        return max1;
    }
};