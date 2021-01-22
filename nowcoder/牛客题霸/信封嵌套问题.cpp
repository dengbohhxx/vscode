class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param letters intvector<vector<>> 
     * @return int
     */
    static bool cmp(const vector<int> a,const vector<int> b)
    {
        if(a[0]==b[0])
            return a[1]>=b[1];
        else
            return a[0]<b[0];
    }
    int LIS(vector<int> vec,int n)
    {
        vector<int> dp(n,0);
        dp[0]=1;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(vec[i]>vec[j])
                    dp[i]=max(dp[i],dp[j]);
            }
            dp[i]++;
        }
        return *max_element(dp.begin(),dp.end());
    }
    int maxLetters(vector<vector<int> >& letters) {
        // write code here
        int n=letters.size();
        sort(letters.begin(),letters.end(),cmp);
        vector<int> height;
        for(int i=0;i<n;i++)
        {
            height.push_back(letters[i][1]);
        }
        int res=LIS(height,n);
        return  res;
    }
};