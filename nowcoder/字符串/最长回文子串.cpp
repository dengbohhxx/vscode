#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <limits.h>
using namespace std;
int getLongestPalindrome(string A, int n) {
        // write code here
        if(A=="")
            return 0;
        if(A.size()==1)
            return 1;
        string B=A;
        reverse(B.begin(),B.end());
        int m=A.size();
        vector<vector<int> >dp(m,vector<int>(m));
        for(int i=0;i<m;i++)
        {
            if(B[i]==A[0])
                dp[i][0]=1;
        }
          for(int i=0;i<m;i++)
        {
            if(B[0]==A[i])
                dp[0][i]=1;
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(B[i]==A[j])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
            }
        }
        int max=INT_MIN;
        for(int i=0;i<m;i++)
        {
            int temp=*max_element(dp[i].begin(),dp[i].end());
            if(temp>max)
                max=temp;
        }
        return max;
    }
int main()
{
    string str;
    while(cin>>str)
    {
        int n=getLongestPalindrome(str, str.size());
        cout<<n<<endl; 
    }






    return 0;
}