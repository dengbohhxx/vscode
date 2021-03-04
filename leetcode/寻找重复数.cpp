class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hash;
        int n=nums.size();
        int res=-1;
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]]>1)
            {
                res=nums[i];
            }
        }
        return res;
    }
};