/*
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
            for(int i=0;i<n;i++)
            {
                if(used[i]==true)
                    continue;
                used[i]=true;
                row.push_back(nums[i]);
                backtrace(nums,index+1,n,used,row,res);
                row.pop_back();
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
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
*/
class Solution {
public:
    void backtrace(vector<int>& nums,int index,int n,vector<vector<int>> &res)
    {
        if(index==n)
        {
            res.push_back(nums);
            return ;
        }
        else
        {
            for(int i=index;i<n;i++)
            {
                swap(nums[i],nums[index]);
                backtrace(nums,index+1,n,res);
                swap(nums[i],nums[index]);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n=nums.size();
        if(n==0)
            return res;
        backtrace(nums,0,n,res);
        return res;
    }
};