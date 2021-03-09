class Solution {
public:
    bool allzero(vector<int> nums)
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                return false;
            }
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        string str;
        int n=nums.size();
        if(n==0)
            return str;
        if(n==1)
            return to_string(nums[0]);
        if(allzero(nums))
            return "0";
        vector<string> vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back(to_string(nums[i]));
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(vec[i]+vec[j]<vec[j]+vec[i])
                {
                    swap(vec[i],vec[j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            str+=vec[i];
        }
        return str;
    }
};