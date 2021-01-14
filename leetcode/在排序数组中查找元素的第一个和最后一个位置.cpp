class Solution {
public:
    int searchleft(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else if(nums[mid]==target)
            {
                right=mid-1;
            }
        }
        if(left>=nums.size()||nums[left]!=target)
                return -1;
        return left;
    }
     int searchright(vector<int>& nums, int target)
    {
        int left=0;
        int right=nums.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]<target)
            {
                left=mid+1;
            }
            else if(nums[mid]>target)
            {
                right=mid-1;
            }
            else if(nums[mid]==target)
            {
                left=mid+1;
            }
        }
        if(right<0||nums[right]!=target)
                return -1;
        return right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res(2,-1);
        if(n==0)
            return res;
        int left=searchleft(nums,target);
        int right=searchright(nums,target);
        if(left==-1||right==-1)
            return res;
        res[0]=left;
        res[1]=right;
        return res;
    }
};