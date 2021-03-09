class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int n=nums.size();
        if(n==0)
            return false;
        for(int i=0;i<n;i++)
        {
            if(hash.count(nums[i])>0)
            {
                if(i-hash[nums[i]]<=k)
                    return true;
            }
            hash[nums[i]]=i;
        }
        return false;
    }
};