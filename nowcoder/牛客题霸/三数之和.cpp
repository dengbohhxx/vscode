class Solution {
public:

   vector<vector<int>> twosum(vector<int> nums,int start,int end,int target,int value)
   {
       vector<vector<int>> answer;
       while(start<end)
       {
           int sum=nums[start]+nums[end];
           if(sum==target)
           {
               vector<int> res;
               res.push_back(value);
               res.push_back(nums[start]);
               res.push_back(nums[end]);
               answer.push_back(res);
               while(start<end&&nums[start]==nums[start+1])
                {
                    start++;
                }
                start++;
                while(start<end&&nums[end]==nums[end-1])
                {
                    end--;
                }
                end--;
           }
           else if(sum>target)
           {
               end--;
           }
           else
           {
               start++;
           }
       }
       return answer;
   }
    vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int> > vec;
            sort(nums.begin(),nums.end());
            int size=nums.size();
            if(size<3)
                return vec;
            for(int i=0;i<size;i++)
            {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            auto row=twosum(nums,i+1,size-1,-nums[i],nums[i]);
            vec.insert(vec.end(),row.begin(),row.end());
            }
            return vec;
    }
};