class Solution {
public:

    int  twosum(vector<int> nums,int index,int target)
    {
        int low=index+1;
        int high=nums.size()-1;
        int best=1e6;
        while(low<high)
        {
            int left=nums[low];
            int right=nums[high];
            int sum=nums[index]+nums[low]+nums[high];
            if(sum==target)
               return target;
            if(abs(sum-target)<abs(best-target))
            {
                best=sum;
            }
            if(sum>target)
            {
                while(low<high&&nums[high]==right)
                            high--;
            }
            else if(sum<target)
            {
                while(low<high&&nums[low]==left)
                            low++;
            }
        }
        return best;
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int best=1e6;
        for(int i=0;i<n;i++)
        {
            int res=twosum(nums,i,target);
            if(abs(res-target)<abs(best-target))
            {
                best=res;
            }
            while(i<n-1&&nums[i]==nums[i+1])
                i++;
        }
        return best;
    }
};