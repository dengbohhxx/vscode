/*
class Palindrome {
public:
    int getLongestPalindrome(string A, int n) {
        // write code here
        vector<vector<bool> > dp(n,vector<bool>(n,false));
        int m=0;
        for(int d=0;d<n;d++)
        {
            for(int i=0;i<n-d;i++)
            {
                int j=i+d;
                if(A[i]==A[j])
                {
                    if(d==0||d==1)
                        dp[i][j]=true;
                    else
                        dp[i][j]=dp[i+1][j-1];
                }
                if(dp[i][j]==true)
                    m=max(m,d+1);
            }
        }
        return m;
    }
};
*/
class Palindrome {
public:
    string manacher(string s)
    {
        string str(2*s.size()+1,'#');
        int index=0;
        for(int i=0;i<str.size();i++)
        {
            str[i]=(i%2==0)?'#':s[index++];
        }
        return str;
    }
    int getLongestPalindrome(string A, int n) {
        // write code here
        if(A.empty()||n==0)
            return 0;
        string str=manacher(A);//1221->#1#2#2#1
        vector<int> arr(str.size(),0);//半径数组
        int c=-1;//取得r的时候的回文中心
        int r=-1;//r整体回文右边界
        int m=INT_MIN;//返回值
        for(int i=0;i<str.size();i++)
        {
            arr[i]=r>i?min(arr[c-(i-c)],r-i):1;
            while(i+arr[i]<str.size()&&i-arr[i]>=0)
            {
                if(str[i+arr[i]]==str[i-arr[i]])
                   arr[i]++;
                else
                    break;
            }
            if(i+arr[i]>r)
            {
                r=i+arr[i];
                c=i;
            }
            m=max(m,arr[i]);
        }
        return m-1;
    }
};
