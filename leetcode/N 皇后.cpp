/*
class Solution {
public:
    void backtrace(int index,int n,vector<bool> &used,vector<int> &col,vector<vector<string>> &vvs)
    {
        if(index==n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i+1;j<n;j++)
                {
                    if(abs(col[i]-col[j])==abs(i-j))
                        return ;
                }
            }
            vector<string> str(n,string(n,'.'));
            for(int i=0;i<n;i++)
            {
                str[i][col[i]]='Q';
            }
            vvs.push_back(str);
            return;
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(used[i]==false)
                {
                    used[i]=true;
                    col.push_back(i);
                    backtrace(index+1,n,used,col,vvs);
                    col.pop_back();
                    used[i]=false;
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col;//列的index
        vector<bool> used(n,false);
        vector<vector<string>> vvs;
        if(n==0)
            return vvs;
        backtrace(0,n,used,col,vvs);
        return vvs;
    }
};
*/
class Solution {
public:
    bool match(int p,vector<int> vec)
    {
        for(int i=0;i<p;i++)
        {
            if(vec[i]==vec[p]||abs(vec[i]-vec[p])==abs(i-p))
                return false;
        }
        return true;
    }
    void fun(int p,int n,vector<int> &col,vector<vector<string> > &vvs)
    {
        if(p==n)
        {
            vector<string> str(n,string(n,'.'));
            for(int i=0;i<n;i++)
            {
                str[i][col[i]]='Q';
            }
            vvs.push_back(str);
            return;
        }
        else
        {
            for(col[p]=0;col[p]<n;col[p]++)
            {
                if(match(p,col))
                {
                    fun(p+1,n,col,vvs);
                }
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n);
        vector<vector<string> > vvs;
        fun(0,n,col,vvs);
        return vvs;
    }
};