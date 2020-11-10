class Finder {
public:
    void maxheap(vector<int> &a,int index,int len)
    {
        int minidx=index;
        while(index<len)
        {
            int left=2*index+1;
            int right=2*index+2;
            if(left<len&&a[left]>a[minidx])
                minidx=left;
            if(right<len&&a[right]>a[minidx])
                minidx=right;
            if(index!=minidx)
            {
                swap(a[minidx],a[index]);
                index=minidx;
            }
            else
            {
                break;
            }
        }
    }
    int findKth(vector<int> a, int n, int K) {
        // write code here
        for(int i=n/2-1;i>=0;i--)
        {
            maxheap(a,i,n);
        }
        for(int i=n-1;i>=n-K+1;i--)
        {
            swap(a[0],a[i]);
            maxheap(a,0,i);
        }
        return a[0];
    }
};