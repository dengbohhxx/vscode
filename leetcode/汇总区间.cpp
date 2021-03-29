class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<string> res;
        if(n==1)
            {
                string temp=to_string(nums[0]);
                res.push_back(temp);
                return res;
            }
        while(i<n)
        {
            int l=i;
            i++;
            while(i<n&&nums[i] == nums[i - 1] + 1)
            {
                i++;
            }
            int r=i-1;
            string temp=to_string(nums[l]);
            if(l<r)
            {
                temp+="->";
                temp+=to_string(nums[r]);
            }
            res.push_back(temp);
        }
        return res;
    }
};