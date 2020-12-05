class Solution {
public:
    void dfs(vector<int> num,int cur,int target,int n,vector<int> &row,vector<vector<int> > &vec)
    {
        if(cur==target)
        {
            vec.push_back(row);
            return;
        }
        else
        {
            for(int i=n;i<num.size();i++)
            {
                if(cur+num[i]>target)//剪枝，后边的数更大，加上cur会更大于target
                        continue;
                if(i>n&&num[i]==num[i-1])//去重，num[i]用过就不能再用了，但是第一次还是能用
                        continue;
                row.push_back(num[i]);
                dfs(num,cur+num[i],target,i+1,row,vec);
                row.pop_back();
            }
        }
    }
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        sort(num.begin(),num.end());
        int n=num.size();
        vector<int> row;
        vector<vector<int> > vec;
        if(n==0)
            return vec;
        dfs(num,0,target,0,row,vec);
        return vec;
    }
};