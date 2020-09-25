class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
        // write code heremalloc()
        for(int i=1;i<n;i++)
        {
            for(int j=i;j>=1;j--)
            {
                if(A[j]<A[j-1])
                {
                    swap(A[j],A[j-1]);
                }
                
            }
        }
        return A;
    }
};