class Solution {
public:
    int numDecodings(string s) {
            int n=s.size();
            if(n==1)
            {
                if(s[0]>'0'&&s[0]<='9')
                    {
                        return 1;
                    }
                else
                    {
                        return 0;
                    }
            }
            if(n==2)
            {
                int k=0;
            if(s[0]>'0'&&s[0]<='9')
            {
                k=1;
            }
            else
            {
                k=0;
            }
            if(s[0]!='0')
            {
                int temp=(s[0]-'0')*10+s[1]-'0';
                if(temp>=1&&temp<=26)
                {
                    if(s[1]=='0')
                        k=1;
                    else if(s[1]!='0')
                        k=2;
                }
                else
                {
                    if(s[1]=='0')
                        k=0;
                }
            }
                return k;
            }
            vector<int> dp(n,0);
             if(s[0]>'0'&&s[0]<='9')
                    {
                        dp[0]=1;
                    }
                else
                    {
                        dp[0]=0;
                    }
            int k=0;
            if(s[0]>'0'&&s[0]<='9')
            {
                k=1;
            }
            else
            {
                k=0;
            }
            if(s[0]!='0')
            {
                int temp=(s[0]-'0')*10+s[1]-'0';
                if(temp>=1&&temp<=26)
                {
                    if(s[1]=='0')
                        k=1;
                    else
                        k=2;
                }
                else
                {
                   if(s[1]=='0')
                        k=0;
                }
            }
            dp[1]=k;
               
        for(int i=2;i<n;i++)
        {
            int temp1=0;
            if(s[i]-'0'>0&&s[i]-'0'<=9)
                temp1=dp[i-1];
            int temp2=0;
            if(s[i-1]!='0')
            {
                int temp=(s[i-1]-'0')*10+s[i]-'0';
                 if(temp>=1&&temp<=26)
                  {
                      temp2=dp[i-2];
                  }      
            }
            dp[i]=temp1+temp2;
        }
        return dp[n-1];
                
    }
};