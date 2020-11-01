class HeapSort {
public:
	/*void adjust(int * A,int len,int index)//递归
	{
	int left = 2 * index + 1;//左
	int right = 2 * index + 2;//右
	int maxidx = index;
	if (left<len && A[left]>A[maxidx])
	maxidx = left;
	if (right<len && A[right]>A[maxidx])
	maxidx = right;//maxidx为最大的下标
	if (maxidx != index)// 如果maxIdx的值有更新
	{
	swap(A[maxidx], A[index]);
	adjust(A, len, maxidx);// 递归调整其他不满足堆性质的部分
	}
	}*/
	void adjust(int * A, int len, int index)//非递归
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

	int* heapSort(int* A, int n) {
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
		return A;
	}
};