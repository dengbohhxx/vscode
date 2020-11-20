class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m=array.size();
        int n=array[0].size();
        bool res=false;
        int i=0;
        int j=n-1;
        while(i<=m-1&&j>=0)
        {
            if(target<array[i][j])
                j--;
            else if(target>array[i][j])
                i++;
            else
            {
                res=true;
                break;
            }
        }
        return res;
    }
};