class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> sets;
        for(int i=0;i<wordDict.size();i++)
        {
            sets.insert(wordDict[i]);
        }
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(dp[j]&&sets.count(s.substr(j,i-j))>0)
                {
                    dp[i]=true;
                }

            }
        }
        return dp[s.size()];
    }
};