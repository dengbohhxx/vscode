class Solution {
public:
    void probability(int index,int n,vector<double>&vec,int sum)
    {
        if(index==n)
            {
                vec[sum-n]++;
                return;
            }
        else
        {
            for(int i=1;i<=6;i++)
            {
                probability(index+1,n,vec,sum+i);
            }
        }

    }
    vector<double> dicesProbability(int n) {
        int maxval=6;
        vector<double> vec((maxval-1)*n+1,0);
        probability(0,n,vec,0);
        for(int i=0;i<vec.size();i++)
        {
            vec[i]/=pow(maxval,n);
        }
        return vec;
    }
};
class Solution {
public:
    vector<double> dicesProbability(int n) {
            vector<vector<int> > dp(n,vector<int>(6*n+1));
            vector<double> ans(5*n+1);
            for(int i=1;i<=6;i++)
            {
                dp[0][i]=1;
            }
            for(int i=1;i<n;i++)
            {
                for(int j=i+1;j<=6*n;j++)
                {
                    for(int k=1;k<=6;k++)
                    {
                        if(j-k>=0)
                        {
                            dp[i][j]+=dp[i-1][j-k];
                        }
                    }
                }
            }
            for(int i=n;i<=6*n;i++)
                    ans[i-n]=dp[n-1][i]/pow(6,n);
            return ans;
    }
};