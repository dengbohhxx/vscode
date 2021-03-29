class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n=nums.size();
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(hash.count(nums[i])>0)
            {
                res=nums[i];
                break;
            }
            hash[nums[i]]++;
        }
        return res;
    }
};