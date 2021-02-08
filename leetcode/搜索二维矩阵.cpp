class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m=matrix.size();
            if(m==0)
                return false;
            int n=matrix[0].size();

            int left=0;
            int right=m*n-1;
            while(left<=right)
            {
                int mid=(left+right)/2;
                int temp=matrix[mid/n][mid%n];
                if(temp==target)
                {
                    return true;
                }
                else if(temp>target)
                {
                    right=mid-1;
                }
                else if(temp<target)
                {
                    left=mid+1;
                }
            }
            return false;
    }
};