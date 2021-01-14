class Solution {
public:
    vector<vector<int> > twosum(vector<int>& nums,int start,int target)
    {
        int low=start;
        int high=nums.size()-1;
        vector<vector<int> > res;
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
                vector<int> temp;
                temp.push_back(nums[low]);
                temp.push_back(nums[high]);
                res.push_back(temp);
                while(low<high&&nums[low]==left)//重复
                    low++;
                while(low<high&&nums[high]==right)//重复
                    high--;
            }
        }
        return res;
    }
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int n=nums.size();
        if(n==0)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            vector<vector<int> > tuple=twosum(nums,i+1,0-nums[i]);
            for(int j=0;j<tuple.size();j++)
            {
                tuple[j].push_back(nums[i]);//注意ij
                res.push_back(tuple[j]);
            }
            while(i<n-1&&nums[i]==nums[i+1])//防止nums[i]重复
                i++;
        }
        return res;
    }
};