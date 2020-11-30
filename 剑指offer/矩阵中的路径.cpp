class Solution {
public:
    bool hasPathcore(char* matrix, int rows, int cols,int row,int col ,string &str1,int &len,int strlen,vector<vector<bool> > &visit)
    {
        if(len==strlen)
            return true;
        bool haspath=false;
        if((row>=0&&row<=rows)&&(col >= 0 && col < cols )&&(matrix[row*cols+col]==str1[len])&&!visit[row][col])
        {
            len++;
            visit[row][col]=true;
            haspath=hasPathcore(matrix,rows,cols,row-1,col,str1,len,strlen,visit)||
                hasPathcore(matrix,rows,cols,row+1,col,str1,len,strlen,visit)||
                hasPathcore(matrix,rows,cols,row,col+1,str1,len,strlen,visit)||
                hasPathcore(matrix,rows,cols,row,col-1,str1,len,strlen,visit);
            if(!haspath)
            {
                len--;
                visit[row][col]=false;
            }
        }
        return haspath;
    }
    
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
       if(matrix==NULL||rows<1||cols<1||str==NULL)
           return false;
        string str1(str);
        int strlen=str1.size();
        vector<vector<bool> > visit(rows,vector<bool>(cols,false));
        int row=0;
        int col=0;
        int len=0;
        for(row=0;row<rows;row++)
        {
            for(col=0;col<cols;col++)
            {
                if(hasPathcore(matrix,rows,cols,row,col,str1,len,strlen,visit))
                    return true;
            }
        }
        return false;
    }


};
class Solution {
public:
    bool haspath(char* matrix, int i,int rows,int j, int cols,string &s,int len,int strlen,vector<vector<bool> > &visited)
    {
        if(len==strlen)
            return true;
        else if(i<0||i>=rows||j<0||j>=cols||matrix[i*cols+j]!=s[len]||visited[i][j]==true)
        {
            return false;
        }
        else
        {
            visited[i][j]=true;
            bool a=haspath(matrix,i+1,rows,j,cols,s,len+1,strlen,visited);
            bool b=haspath(matrix,i-1,rows,j,cols,s,len+1,strlen,visited);
            bool c=haspath(matrix,i,rows,j+1,cols,s,len+1,strlen,visited);
            bool d=haspath(matrix,i,rows,j-1,cols,s,len+1,strlen,visited);
            if(a||b||c||d)
                return a||b||c||d;
            else
                visited[i][j]=false;
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        if(matrix==NULL||rows==0||cols==0||str==0)
            return false;
        string s(str);
        int strlen=s.size();
        vector<vector<bool> > visited(rows,vector<bool>(cols,false));
        int len=0;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(haspath(matrix,i,rows,j,cols,s,len,strlen,visited))
                    return true;
            }
        }
        return false;
    }
};