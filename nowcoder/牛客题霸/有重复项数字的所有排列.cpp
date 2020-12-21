class Solution {
public:
    void dfs(vector<int> num,int start,int end,vector<vector<int> > &vec)
    {
        if(start==end)
        {
            int n=vec.size();
            for(int i=0;i<n;i++)
            {
                if(vec[i]==num)
                    return ;
            }
            vec.push_back(num);
            return;
        }
        else
        {
            for(int i=start;i<num.size();i++)
            {
                swap(num[start],num[i]);
                dfs(num,start+1,end,vec);
                swap(num[start],num[i]);
            }
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        int n=num.size();
        vector<int> row;
        vector<vector<int> > vec;
        if(n==0)
            return vec;
        dfs(num,0,n,vec);
        return vec;
    }
};