class Solution {
public:
   /*
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
    */
     void dfs(int p,int n,vector<int> &vec,vector<vector<string> > &vvs,vector<int> &use)
     {
       if(p==n)
        {
           for(int i=0;i<n;i++)
           {
               for(int j=i+1;j<n;j++)
               {
                   if(abs(vec[i]-vec[j])==abs(i-j))
                     return;
               }
           }
            vector<string> str(n,string(n,'.'));  
            for(int i=0;i<n;i++)
            {
                str[i][vec[i]]='Q';
            }
            vvs.push_back(str);
            return;
        }  
         for(int i=0;i<n;i++)
         {
             if(use[i])
             {
                 use[i]=false;
                 vec.push_back(i);
                 dfs(p+1,n,vec,vvs,use);
                 vec.pop_back();
                 use[i]=true;
             }
         }
         
         
     }
    vector<vector<string>> solveNQueens(int n)
    {
     vector<int> vec;   
     vector<int> use(n,1);  
    vector<vector<string>> vvs;
    dfs(0,n,vec,vvs,use);
    return vvs;
        } 
};