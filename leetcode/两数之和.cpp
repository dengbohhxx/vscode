class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> a;
        vector<int> vec;
        for(int i=0;i<nums.size();i++)
        {
            if(a.count(target-nums[i])>0)
            {
                vec.push_back(a[target-nums[i]]);
                vec.push_back(i);
                break;
            }
            a.insert(map<int,int>::value_type(nums[i],i));
        }
        return vec;
    }
};