class Solution {
public:
    void backtrace(int start,int sum,int n,int index,int k,vector<int> &row,vector<vector<int> > &res)
    {
        if(sum==n&&index==k)
        {
            res.push_back(row);
        }
        else
        {
            for(int i=start;i<=9;i++)
            {
                row.push_back(i);
                backtrace(i+1,sum+i,n,index+1,k,row,res);
                row.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> row;
        vector<vector<int> > res;
        if(n==0||k==0)
            return res;
        backtrace(1,0,n,0,k,row,res);
        return res;
    }
};