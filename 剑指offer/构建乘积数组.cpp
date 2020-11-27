class Solution {
public:
    vector<int> multiply(const vector<int>& A)
    {
        int n=A.size();
         vector<int> B(n);
        if(n==0)
            return B;
        
         B[0]=1;
        for(int i=1;i<n;i++)
        {
            B[i]=B[i-1]*A[i-1];
        }
        int temp=1;
        for(int i=n-1;i>=0;i--)
        {
            B[i]*=temp;
            temp*=A[i];
        }
        return B;
    }
};