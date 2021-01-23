class Solution {
public:
    void backtrace(int n,int start,int k,vector<int> &row, vector<vector<int> > &res)
    {
        if(row.size()==k)
        {
            res.push_back(row);
            return;
        }
        else
        {
            for(int i=start;i<=n;i++)
            {
                row.push_back(i);
                backtrace(n,i+1,k,row,res);
                row.pop_back();
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> row;
        vector<vector<int> > res;
        if(n==0||k==0)
                return res;
        backtrace(n,1,k,row,res);
        return res;
    }
};