class Checker {
public:
void adjust(vector<int> &A, int len, int index)//非递归
	{
     
	 int maxidx = index;
        while(index<len)
        {
            int left = 2 * index + 1;//左
	        int right = 2 * index + 2;//右
            if (left<len && A[left]>A[maxidx])
	                maxidx = left;
	        if (right<len && A[right]>A[maxidx])
	               maxidx = right;//maxidx为最大的下标
            if(maxidx != index)
            {
                swap(A[maxidx], A[index]);
                index=maxidx;
            }
            else 
                break;
        }
	}

	void heapsort(vector<int> &A, int n) {
		// write code here
		for (int i = n / 2 - 1; i >= 0; i--)  // 对每一个非叶结点进行堆调整(从最后一个非叶结点开始)
		{
			adjust(A, n, i);
		}
		for (int i = n - 1; i >= 1; i--)
		{
			swap(A[0], A[i]);           // 将当前最大的放置到数组末尾
			adjust(A, i, 0);              // 将未完成排序的部分继续进行堆排序
		}
	}
    bool checkDuplicate(vector<int> a, int n) {
        // write code here
        heapsort(a,n);
        int res=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                res=1;
            }
        }
        return res;
    }
};