class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 
     * @param a int整型vector<vector<>> 第一个矩阵
     * @param b int整型vector<vector<>> 第二个矩阵
     * @return int整型vector<vector<>>
     */
    int multply(vector<vector<int> > a,int i, vector<vector<int> > b,int j)
    {
        int n=a.size();
        int sum=0;
        for(int k=0;k<n;k++)
        {
            sum+=a[i][k]*b[k][j];
        }
        return sum;
    }
    vector<vector<int> > solve(vector<vector<int> >& a, vector<vector<int> >& b) {
        // write code here
        int n=a.size();
        vector<vector<int> > vec(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                vec[i][j]=multply(a,i,b,j);
            }
        }
        return vec;
    }
};