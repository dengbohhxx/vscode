class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n=nums.size();
        if(n==0)
            return false;
        for(int i=0;i<n;i++)
        {
            if(hash.count(nums[i])>0)
            {
                return true;
            }
            hash[nums[i]]++;
        }
        return false;
    }
};