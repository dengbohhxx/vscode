class ScaleSort {
public:
    
    void adjust(vector<int> &A,int index,int len)
    {
        int maxidx=index;
        while(index<len)
        {
            int left=index*2+1;
            int right=index*2+2;
            if(left<len&&A[left]<A[maxidx])
               maxidx=left;
            if(right<len&&A[right]<A[maxidx])
               maxidx=right;
            if(maxidx!=index)
            {
                swap(A[index],A[maxidx]);
                index=maxidx;
            }
            else
                break;
        }
    }
    void minheap(vector<int> &A,int n)
    {
        for(int i=n/2-1;i>=0;i--)
        adjust(A,i,n);
    }
    vector<int> sortElement(vector<int> A, int n, int k) {
        // write code here
        vector<int> B;
        for(int i=0;i<k;i++)
         B.push_back(A[i]);
        
        minheap(B,k);
        
        for(int i=0;i<n-k;i++)
        {
            A[i]=B[0];
            B[0]=A[i+k];
            adjust(B,0,k);
        }
        
        for(int j=n-k;j<n;j++)
        {
            A[j] =B[0];
            if(j==n-1)
                break;
            B[0]=B[--k];
            adjust(B,0,k);
        }
        return A;
    }
};