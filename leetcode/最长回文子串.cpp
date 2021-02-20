/*
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return "";
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        int m=0;
        int index=0;
        for(int d=0;d<n;d++)
        {
            for(int i=0;i<n-d;i++)
            {
                int j=i+d;
                if(s[i]==s[j])
                {
                    if(d==0||d==1)
                        dp[i][j]=true;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true)
                {
                    m=max(m,d+1);
                    index=i;
                }
            }
        }
        return s.substr(index,m);
    }
};
*/
class Solution {
public:
    string palindrome(string &s,int l,int r)
    {
        while(l>=0&&r<s.size()&&s[l]==s[r])
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) {
        string res;
        for(int i=0;i<s.size();i++)
        {
            string s1=palindrome(s,i,i);
            string s2=palindrome(s,i,i+1);
            res=res.size()>s1.size()?res:s1;
            res=res.size()>s2.size()?res:s2;
        }
        return res;
    }
};