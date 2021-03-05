class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int> > vec;
        vector<int> zuobiao(2,0);
        int m=matrix.size();
        if(m==0)
            return;
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    zuobiao[0]=i;
                    zuobiao[1]=j;
                    vec.push_back(zuobiao);
                }
            }
        }
        int l=vec.size();
        for(int k=0;k<l;k++)
        {
            for(int i=0;i<n;i++)
            {
                matrix[vec[k][0]][i]=0;
            }
            for(int i=0;i<m;i++)
            {
                matrix[i][vec[k][1]]=0;
            }
        }

    }
};