class Solution {
public:
    vector<vector<int> > nsum(vector<int>& nums,int n,int start, int target)
    {
        int size=nums.size();
        vector<vector<int> > res;
        if(n<2||size<n)
            return res;
        if(n==2)
        {
            int low=start;
            int high=nums.size()-1;
            while(low<high)
            {
                int sum=nums[low]+nums[high];
                int left=nums[low];
                int right=nums[high];
                if(sum<target)
                {
                    while(low<high&&nums[low]==left)//重复
                        low++;
                }
                else if(sum>target)
                {
                    while(low<high&&nums[high]==right)//重复
                    high--;
                }
                else
                {
                    res.push_back({nums[low],nums[high]});
                    while(low<high&&nums[low]==left)//重复
                                low++;
                    while(low<high&&nums[high]==right)//重复
                                high--;
                }
            }
        }
        else
        {
            for(int i=start;i<size;i++)
            {
                vector<vector<int> > sub=nsum(nums,n-1,i+1,target-nums[i]);
                for(int j=0;j<sub.size();j++)
                {
                    sub[j].push_back(nums[i]);
                    res.push_back(sub[j]);
                }
                while(i<size-1&&nums[i]==nums[i+1])
                            i++;
            }
        }
        return res;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return nsum(nums,4,0,target);
    }
};