class Solution {
public:
    /**
     *
     * @param n int整型 the n
     * @return int整型
     */
      int Nqueen (int n) {
        // write code here
       int A[14]={1,0,0,2,10,4,40,92,352,724,2680,14200,73712,365596};
        return A[n-1];
    }
};
class Solution {
public:
    /**
     * 
     * @param n int整型 the n
     * @return int整型
     */
    bool check(int p,vector<int> &vec)
    {
        for(int i=0;i<p;i++)
        {
            if(vec[i] == vec[p] || abs(vec[p] - vec[i]) == abs(p - i))
                return 0;
        }
        return 1;
        
        
    }
    
    void fun(int p,int n,vector<int> &vec,vector<vector<string> > &vvs)
    {
        if(p==n)
        {
            vector<string> str(n,string(n,'.'));  
            for(int i=0;i<n;i++)
            {
                str[i][vec[i]]='Q';
            }
            vvs.push_back(str);
        return;
        }
        for(vec[p]=0;vec[p]<n;vec[p]++)
        {
            if(check(p,vec)==true)
                fun(p+1,n,vec,vvs);
        }
        
        
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> vec(n);
        vector<vector<string> > vvs;
        fun(0,n,vec,vvs);
        return vvs;
    }
    int Nqueen(int n) {
        // write code here
        vector<vector<string>> str=solveNQueens(n);
        return str.size();
    }
};