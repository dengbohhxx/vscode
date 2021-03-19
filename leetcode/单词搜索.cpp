class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int &idx,int len,int i,int j,int m,int n,vector<vector<bool> > &visited,vector<vector<int> > &direction)
    {
        if(idx==len-1)
        {
            return true;
        }
        for(int k=0;k<4;k++)
        {
            if(visited[i][j]==false)
            {
                visited[i][j]=true;
                idx++;
                int newi=i+direction[k][0];
                int newj=j+direction[k][1];
                if(newi>=0&&newi<m&&newj>=0&&newj<n&&board[newi][newj]==word[idx]&&visited[newi][newj]==false)
                {
                    if(dfs(board,word,idx,len,newi,newj,m,n,visited,direction))
                    {
                        return true;
                    }
                }
                idx--;
                visited[i][j]=false;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        if(m==0)
            return false;
        int n=board[0].size();
        vector<vector<bool> > visited(m,vector<bool>(n,false));
         vector<vector<int> > direction={{-1,0},{1,0},{0,-1},{0,1}};
        int idx=0;
        int len=word.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                   bool flag=dfs(board,word,idx,len,i,j,m,n,visited,direction);
                   if(flag)
                   {
                       return true;
                   }
                }
            }
        }
        return false;
    }
};