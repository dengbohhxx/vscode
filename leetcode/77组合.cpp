class Solution {
public:
    void fun(int n,int k,int xth,int m,vector<int> &a,vector<vector<int>>&vec)
    {
        if(xth==k)
        {
           vec.push_back(a);
            return;
        }
        for(int i=m;i<=n;i++)
        {
            a[xth]=i;
            fun(n,k,xth+1,i+1,a,vec);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> a(k);
        vector<vector<int> >vec;
        fun(n,k,0,1,a,vec);
        return vec;
    }
};