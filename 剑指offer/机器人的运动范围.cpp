class Solution {
public:
    int sumnum(int num)
    {
        int res=0;
        while(num!=0)
        {
            res+=num%10;
            num=num/10;
        }
        return res;
    }
    int counting(int threshold, int i,int rows, int j,int cols,vector<vector<bool> > &visited)
    {
        if(sumnum(i)+sumnum(j)>threshold||i<0||i>=rows||j<0||j>=cols||visited[i][j]==true)
            return 0;
        else
        {
            int res=1;
            visited[i][j]=true;
            res=res+counting(threshold,i+1,rows,j,cols,visited)+counting(threshold,i-1,rows,j,cols,visited)+
                counting(threshold,i,rows,j+1,cols,visited)+counting(threshold,i,rows,j-1,cols,visited);
            return res;
        }
    }
    int movingCount(int threshold, int rows, int cols)
    {
        if(threshold==0||rows<=0|cols<=0)
            return 0;
        vector<vector<bool> > visited(rows,vector<bool>(cols,false));
        int k=counting(threshold,0,rows,0,cols,visited);
        return k;
    }
};