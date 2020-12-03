class Finder {
public:
    vector<int> findElement(vector<vector<int> > mat, int n, int m, int x) {
        // write code here
        vector<int> vec;
        if(n==0||m==0)
            return vec;
        int i=0;
        int j=m-1;
        while(i<n&&j>=0)
        {
            if(mat[i][j]==x)
            {
                vec.push_back(i);
                vec.push_back(j);
                break;
            }
            else if(mat[i][j]<x)
                i++;
            else
                j--;
        }
        return vec;
    }
};