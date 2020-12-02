class Rotate {
public:
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        // write code here、
        
        vector<vector<int> > vec;
        vector<int> row;
        if(mat.size()==0)
            return vec;
        for(int j=0;j<n;j++)
        {
            for(int i=n-1;i>=0;i--)
            {
                row.push_back(mat[i][j]);
            }
            vec.push_back(row);
            row.clear();
        }
        return vec;
    }
};