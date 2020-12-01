class Solution {
public:
    /**
     * 
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型vector
     */
    vector<int> printMatrix(vector<vector<int> >& matrix) {
        // write code here
        
        vector<int> vec;
        if(matrix.size()==0)
            return vec;
        int row=matrix.size();
        int col=matrix[0].size();
        int left=0;
        int right=col-1;
        int top=0;
        int bot=row-1;
        while(left<=right&&top<=bot)
        {
            for(int i=left;i<=right;i++)
                vec.push_back(matrix[top][i]);
            if(top<bot)
            {
                for(int i=top+1;i<=bot;i++)
                {
                    vec.push_back(matrix[i][right]);
                }
            }
            if(top<bot&&left<right)
            {
                for(int i=right-1;i>=left;i--)
                {
                    vec.push_back(matrix[bot][i]);
                }
            }
            if(top+1<bot&&left<right)
            {
                for(int i=bot-1;i>=top+1;i--)
                {
                    vec.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bot--;
        }
        return vec;
    }
};