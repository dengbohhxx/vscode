class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 多次求交叉乘
     * @param a int整型vector a1,a2,...,an
     * @param query int整型vector l1,r1,l2,r2,...,lq,rq
     * @return int整型vector
     */
    vector<int> getSum(vector<int>& a, vector<int>& query) {
        // write code here
        int n=a.size();
        vector<__int128> sum(n+1,0);
        vector<__int128> sumsquare(n+1,0);
        for(int i=0;i<n;i++)
        {
            sum[i+1]=sum[i]+a[i];
            sumsquare[i+1]=sumsquare[i]+(long long)a[i]*a[i];
        }
        vector<int> ans((int)query.size()/2,0);
        for(int i=0;i<query.size();i+=2)
        {
            int l=query[i];
            int r=query[i+1];
            __int128 temp=sum[r]-sum[l-1];
            temp=temp*temp-(sumsquare[r]-sumsquare[l-1]);
            temp/=2;
            temp%=1000000007;
            ans[i/2]=temp;
        }
        return ans;
    }
};