/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n+1,0);
        for(int i=0;i<nums.size();i++)
        {
            vec[nums[i]]++;
        }
        vector<int> res;
        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]==0)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            int newindex=abs(nums[i])-1;
            if(nums[newindex]>0)
            {
                nums[newindex]*=-1;
            }
        }
        vector<int> res;
        for(int i=1;i<=nums.size();i++)
        {
            if(nums[i-1]>0)
                res.push_back(i);
        }
        return res;
    }
};