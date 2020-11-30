class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> 
     * @param target int整型 
     * @return bool布尔型
     */
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        // write code here
        if(matrix.empty())
            return false;
        int row=matrix.size();
        int col=matrix[0].size();
        int i=0;
        int j=col-1;
        bool res=false;
        while(i<row&&j>=0)
        {
            if(matrix[i][j]==target)
            {
                res=true;
                break;
            }
            else if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return res;
    }
};