class MinValue {
public:
    int getMin(vector<int> arr, int n) {
	// write code here
	int left = 0;
	int right = n - 1;
	int mid = 0;
	int Min = 0;
	if (arr[left]<arr[right])
		return arr[left];

	while (left<right)
	{
		mid = (left + right) / 2;
		if (arr[left]>arr[mid])
		{
			
			if (right == left + 1)
				return min(arr[left], arr[right]);
            right = mid;
			continue;
		}
		else if (arr[mid]>arr[right])
		{
			
			if (right == left + 1)
				return min(arr[left], arr[right]);
            left = mid;
			continue;
		}
		else
		{

			while (left<right)
			{
				Min = arr[left] <= arr[right] ? arr[left] : arr[right];
				left = left + 1;

			}
				
		}

	}
return Min;
}
};