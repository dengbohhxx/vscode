class Solution {
public:
    bool dfs(int idx,int n,int &ith,int k,string &str,string &s,vector<bool> &used)
    {
        if(idx==n)
        {
            ith++;
            if(ith==k)
            {
                s=str;
                return true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(used[i-1]==false)
            {
                used[i-1]=true;
                str.push_back(i+'0');
                if(dfs(idx+1,n,ith,k,str,s,used))
                    return true;
                str.pop_back();
                used[i-1]=false;
            }
        }
        return false;
    }
    string getPermutation(int n, int k) {
        if(n<=0||k<=0)
            return "";
        string str;
        string s;
        vector<bool> used(n,false);
        int ith=0;
        dfs(0,n,ith,k,str,s,used);
        return s;
    }
};