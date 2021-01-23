class Solution {
public:
     void backtrace(vector<int>& nums, vector<int> &row,vector<vector<int> > &res,int start,int end)
    {
        res.push_back(row);
        set<int> used;
        for(int i=start;i<end;i++)
        {
            if(used.count(nums[i])>0)
                continue;
            used.insert(nums[i]);
            row.push_back(nums[i]);
            backtrace(nums,row,res,i+1,end);
            row.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int> row;
        vector<vector<int> > res;
        if(n==0)
            return res;
        sort(nums.begin(), nums.end());
        backtrace(nums,row,res,0,n);
        return res;
    }
};