class QuickSort {
public:
    int partation(int *A,int start,int end)
    {
        int i=start;
        int j=end;
        int key=A[start];
        while(i<j)
        {
            while(i<j&&A[j]>=key)
                 j--;
            while(i<j&&A[i]<=key)
                 i++;
            if(i<j)
                swap(A[i],A[j]);
        }
        A[start]=A[i];
        A[i]=key;
    return i;
    }
    void qsort(int *A,int start,int end)
    {
        if(start>=end)
            return;
        else
        {
            int j=partation(A,start,end);
            qsort(A,start,j-1);
            qsort(A,j+1,end);
        }
    }
    int* quickSort(int* A, int n) {
        // write code here
        qsort(A,0,n-1);
        return A;
    }
};