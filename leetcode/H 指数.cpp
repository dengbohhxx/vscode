class Solution {
public:
    static bool cmp(int a,int b)
    {
        return a>b;
    }
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n==0)
            return 0;
        sort(citations.begin(),citations.end(),cmp);
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(citations[i]>=i+1)
            {
                k++;
            }
        }
        return k;
    }
};