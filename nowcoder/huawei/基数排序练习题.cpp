class RadixSort {
public:
    int maxbit(int* A, int n)
	{
		int d = 1;
		int p = 10;
		for (int i = 0; i<n; i++)
		{
			while (A[i]>p)
			{
				p *= 10;
				d++;
			}
		}
		return d;
	}
    int* radixSort(int* A, int n) {
        // write code here
        int m=maxbit(A,n);
        for(int i=0;i<=m;i++){//总共几位数
            distribute(A,n,i);
        }
        return A;
    }
    void distribute(int *A,int n,int times){
        vector<vector<int> >vec(10);
        for(int i=0;i<n;i++){
            int num=A[i]/pow(10,times);//得到几位数之前的数
            vec[num%10].push_back(A[i]);
        }
         
        //shouji 
        int index=0;
        for(int i=0;i<10;i++){
           int size=vec[i].size();
            for(int j=0;j<size;j++)
            {
                A[index++]=vec[i][j];
            }
        }
    }
};