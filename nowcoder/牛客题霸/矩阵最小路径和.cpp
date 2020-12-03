#include<iostream>
#include<vector>
using namespace std;


int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==0)
            return -1;
        vector<vector<int> > dp(m,vector<int>(n,0));
        int temp=0;
        for(int i=0;i<m;i++)
        {
            dp[i][0]=temp+matrix[i][0];
            temp=dp[i][0];
        }
        temp=0;
        for(int i=0;i<n;i++)
        {
            dp[0][i]=temp+matrix[0][i];
            temp=dp[0][i];
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+matrix[i][j];
            }
        }
        return dp[m-1][n-1];
}
int main()
{
    vector<int > vec1;
    vector<vector<int> > vec;
     vec1.push_back(1);
     vec1.push_back(3);
     vec1.push_back(5);
     vec1.push_back(9);
    vec.push_back(vec1);
    vec1.clear();
     vec1.push_back(8);
     vec1.push_back(1);
     vec1.push_back(3);
     vec1.push_back(4);
    vec.push_back(vec1);
    vec1.clear();
     vec1.push_back(5);
     vec1.push_back(0);
     vec1.push_back(6);
     vec1.push_back(1);
    vec.push_back(vec1);
    vec1.clear();
     vec1.push_back(8);
    vec1.push_back(8);
     vec1.push_back(4);
     vec1.push_back(0);
    vec.push_back(vec1);
    vec1.clear();

    cout<<minPathSum(vec)<<endl;

}