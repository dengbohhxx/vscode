class MergeSort {
public:
	void merge(int* A, int start, int mid, int end)
	{
		vector<int> temp(end - start + 1);//创建临时数组
		for (int i = start; i <= end; i++)
		{
			temp[i - start] = A[i];//将临时数组赋值为原数组
		}
		int i = start;
		int j = mid + 1;
		for (int k = start; k <= end; k++)
		{
			if (i>mid)//如果i>mid
			{
				A[k] = temp[j - start];
				j++;
			}
			else if (j>end)//如果j>end
			{
				A[k] = temp[i - start];
				i++;
			}
			else if (temp[i - start]<temp[j - start])
			{
				A[k] = temp[i - start];
				i++;
			}
			else
			{
				A[k] = temp[j - start];
				j++;
			}

		}
	}
	void Mergesort(int* A, int start, int end)
	{
		if (start >= end)
			return;
		else
		{
			int mid = (start + end) / 2;//典型二分搜索
			Mergesort(A, start, mid);
			Mergesort(A, mid + 1, end);//注意+1
			merge(A, start, mid, end);
		}
	}
	int* mergeSort(int* A, int n) {
		// write code here
		Mergesort(A, 0, n - 1);
		return A;
	}
};