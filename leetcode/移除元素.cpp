/*
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //sort(nums.begin(),nums.end());
        for(vector<int>::iterator iter=nums.begin();iter!=nums.end();)
        {
            if((*iter)==val)
                {
                    iter=nums.erase(iter);
                }
            else
            {
                iter++;
            }
        }
        int n=nums.size();
        return n;
    }
};
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0;
        for(int j=0;j<nums.size();j++)
        {
            if(nums[j]==val)
                continue;
            nums[i]=nums[j];
            i++;
        }
        return i;
    }
};