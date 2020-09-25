class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
        // write code here
        for(int i=0;i<n;i++)
        {
            int temp=A[i];
            int indix=i;
            for(int j=i+1;j<n;j++)
            {
                if(temp>A[j])
                {
                    temp=A[j];
                    indix=j;
                }
                
            }
            swap(A[i],A[indix]);
        }
        return A;
    }
};