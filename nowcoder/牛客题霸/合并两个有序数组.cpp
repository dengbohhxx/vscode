class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int p1=m-1;
        int p2=n-1;
        int p3=m+n-1;
        while(p1>=0&&p2>=0)
        {
            if(A[p1]>=B[p2])
            {
                A[p3]=A[p1];
                p3--;
                p1--;
            }
            else
            {
                A[p3]=B[p2];
                p3--;
                p2--;
            }
        }
        while(p2>=0)
        {
            A[p3]=B[p2];
            p2--;
            p3--;
        }
    }
};