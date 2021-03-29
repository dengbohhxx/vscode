class Solution {
public:
    void dfs(string &s,vector<vector<int> > &dp,vector<string> &row,vector<vector<string> > &vec,int index)
    {
        if(index==s.size())
        {
            vec.push_back(row);
            return;
        }
        for(int i=index;i<s.size();i++)
        {
            if(dp[index][i]==1)
            {
                row.push_back(s.substr(index,i-index+1));
                dfs(s,dp,row,vec,i+1);
                row.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> row;
        vector<vector<string> > vec;
        int n=s.size();
        if(n==0)
            return vec;
        vector<vector<int> > dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(s[i]==s[j])
                {
                    if(j-i==1)
                        dp[i][j]=1;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
            }
        }
        int index=0;
        dfs(s,dp,row,vec,index);
        return vec;
    }
};