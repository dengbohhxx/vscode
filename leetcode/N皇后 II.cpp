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
    void fun(int p,int n,vector<int> &col,vector<vector<string> > &vvs,int &k)
    {
        if(p==n)
        {
            k++;
            return;
        }
        else
        {
            for(col[p]=0;col[p]<n;col[p]++)
            {
                if(match(p,col))
                {
                    fun(p+1,n,col,vvs,k);
                }
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> col(n);
        vector<vector<string> > vvs;
        int k=0;
        fun(0,n,col,vvs,k);
        return k;
    }
};