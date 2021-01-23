class Solution {
public:
    void backtrace(vector<int>& candidates,int start,int n,int sum,int target,vector<int> &row,vector<vector<int> > &res)
    {
        if(sum==target)
        {
            res.push_back(row);
            return;
        }
        if(sum>target)
        {
            return;
        }
        else
        {
            set<int> used;
            for(int i=start;i<n;i++)
            {
                if(used.count(candidates[i])>0)
                    continue;
                used.insert(candidates[i]);
                row.push_back(candidates[i]);
                backtrace(candidates,i+1,n,sum+candidates[i],target,row,res);
                row.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> row;
        vector<vector<int> > res;
        int n=candidates.size();
        if(n==0)
            return res;
        sort(candidates.begin(),candidates.end());
        backtrace(candidates,0,n,0,target,row,res);
        return res;
    }
};