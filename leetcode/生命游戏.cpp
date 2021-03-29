class Solution {
public:
    int countlives(vector<vector<int> > &copyboard,vector<int>  neighbors,int row,int col)
    {
        int res=0;
        int m=copyboard.size();
        int n=copyboard[0].size();
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(!(neighbors[i]==0&&neighbors[j]==0))
                {
                    int r=row+neighbors[i];
                    int c=col+neighbors[j];
                    if((r < m && r >= 0) && (c < n && c >= 0) && (copyboard[r][c] == 1))
                            res++;
                }
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>  neighbors={-1,0,1};
        int m=board.size();
        if(m==0)
            return;
        int n=board[0].size();
        vector<vector<int> >copyboard(m, vector<int>(n, 0));

        // 从原数组复制一份到 copyBoard 中
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++) {
                copyboard[i][j] = board[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int liveNeighbors=countlives(copyboard,neighbors,i,j);
                if(copyboard[i][j]==1&&(liveNeighbors<2||liveNeighbors>3))
                {
                    board[i][j]=0;
                }
                if(copyboard[i][j]==1&&(liveNeighbors==2||liveNeighbors==3))
                {
                    board[i][j]=1;
                }
                if(copyboard[i][j]==0&&(liveNeighbors==3))
                {
                    board[i][j]=1;
                }
            }
        }

    }
};