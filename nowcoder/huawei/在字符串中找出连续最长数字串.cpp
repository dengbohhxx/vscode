#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    string s;
    while(cin>>s)
    {
        int n=s.size();
        if(n==0)
        {
            cout<<s<<','<<n<<endl;
        }
        vector<int> dp(n);
        if(s[0]>='0'&&s[0]<='9')
            dp[0]=1;
        for(int i=1;i<n;i++)
        {
            if(s[i]>='0'&&s[i]<='9')
                dp[i]=dp[i-1]+1;
            else
                dp[i]=0;
        }
        int max=*max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++)
        {
            if(dp[i]==max)
            {
                for(int j=i-max+1;j<=i;j++)
                    cout<<s[j];
            }
        }
        cout<<','<<max<<endl;
    }
    
    return 0;
}