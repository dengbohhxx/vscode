class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m>0)
        {
            int n=matrix[0].size();
            persum.resize(m + 1, vector<int>(n + 1));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    persum[i+1][j+1]=persum[i][j+1]+persum[i+1][j]-persum[i][j]+matrix[i][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res=persum[row2+1][col2+1]-persum[row1][col2+1]-persum[row2+1][col1]+persum[row1][col1];
        return res;
    }
private:
    vector<vector<int> > persum;

};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */