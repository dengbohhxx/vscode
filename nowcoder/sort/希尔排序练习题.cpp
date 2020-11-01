class ShellSort {
public:
    void process(int* A,int length,int step)
    {
        for(int i=step;i<length;i++)
        {
            int cur=i;
            while(cur>=step)
            {
                int pre=cur-step;
                if(A[cur]<A[pre])
                {
                    swap(A[cur],A[pre]);
                    cur=pre;
                }
                else
                  break;
            }
        }
    }
    int* shellSort(int* A, int n) {
        // write code here
        for(int i=3;i>0;i--)
            process(A,n,i);
        return A;
    }
};