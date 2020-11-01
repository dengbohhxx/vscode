class CountingSort {
public:
    int* countingSort(int* A, int n) {
        // write code here
        if(A==NULL||n<2)
            return A;
        int max=A[0];
        int min=A[0];
        for(int i=0;i<n;i++)
        {
            if(A[i]>max)
                max=A[i];
            if(A[i]<min)
                min=A[i];
        }
        int len=max-min+1;
        vector<vector<int> > vec(len);
        for(int i=0;i<n;i++)
            vec[A[i]-min].push_back(A[i]);
        int count=0;
        for(int i=0;i<len;i++)
        {
            if(!vec[i].empty())
                for(vector<int>::iterator iter=vec[i].begin();iter!=vec[i].end();iter++)
                {
                    A[count++]=*iter;
                }
            
        }
        return A;
    }
};