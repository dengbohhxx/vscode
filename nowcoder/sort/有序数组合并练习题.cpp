class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        // write code here
        int i=n-1;
        int j=m-1;
        int k=m+n-1;
        while(i>=0&&j>=0)
        {
            if(A[i]>B[j])
            {
                A[k]=A[i];
                i--;
            }
            else
            {
                A[k]=B[j];
                j--;
            }
            k--;
        }
        while(j>=0)
        {
            A[k]=B[j];
                j--;
            k--;
        }
        return A;
    }
};