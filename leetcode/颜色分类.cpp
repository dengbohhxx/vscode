class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
        }
        nums.clear();
        for(int i=0;i<=2;i++)
        {
            int temp=hash[i];
            for(int j=0;j<temp;j++)
            {
                nums.push_back(i);
            }
        }
    }
};