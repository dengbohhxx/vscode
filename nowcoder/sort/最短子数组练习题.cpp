class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        // write code here
        int max=INT_MIN;
        int min=INT_MAX;
        int p=0;
        int q=0;
        for(int i=0;i<n;i++)
        {
            if(A[i]>=max)
            {
                max=A[i];
            }
            else
            {
                p=i;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(A[i]<=min)
            {
                min=A[i];
            }
            else
            {
                q=i;
            }
        }
         if(p==q)
            return 0;
        return p-q+1;
    }
};