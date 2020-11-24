class Solution {
public:
    void dfs(string str,vector<string> &vec,vector<int> &use,string s,int p,int n)
    {
        if(p==n)
        {
            int m=vec.size();
                for(int i=0;i<m;i++)
                {
                    if(vec[i]==s)
                       return;
                }
            vec.push_back(s);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(use[i])
            {
                use[i]=0;
                s.push_back(str[i]);
                dfs(str,vec,use,s,p+1,n);
                 use[i]=1;
                s.pop_back();
            }
        }
        
        
    }
    vector<string> Permutation(string str) {
        vector<string> vec;
        string s;
        int n=str.size();
        if(n==0)
            return vec;
        vector<int> use(n,1);
        dfs(str,vec,use,s,0,n);
        return vec;
    }
};