class Solution {
public:
 void backtrace(vector<int>& nums,int index,int n,vector<bool> &used,vector<int> &row,vector<vector<int>> &res)
    {
        if(index==n)
        {
            res.push_back(row);
            return ;
        }
        else
        {
            set<int> uset;
            for(int i=0;i<n;i++)
            {
                if(used[i]==true)
                    continue;
                if(uset.count(nums[i])>0)
                    continue;
                uset.insert(nums[i]);
                used[i]=true;
                row.push_back(nums[i]);
                backtrace(nums,index+1,n,used,row,res);
                row.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> res;
        vector<int> row;
        int n=nums.size();
        vector<bool> used(n,false);
        if(n==0)
            return res;
        backtrace(nums,0,n,used,row,res);
        return res;
    }
};