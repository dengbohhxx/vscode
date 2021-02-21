/*
class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        // write code here
        int left=0;
        int right=n-1;
        int res=-1;
        if(arr[left]<arr[right])
            return arr[left];
        while(left<right)
        {
            int mid=left+(right-left)/2;
            if(arr[left]>arr[mid])
            {
                if(right==left+1)
                {
                    return min(arr[left],arr[right]);
                }
                right=mid;
                continue;
            }
            else if(arr[mid]>arr[right])
            {
                if(right==left+1)
                    return min(arr[left],arr[right]);
                left=mid;
                continue;
            }
            else
            {
                int Min=arr[left];
                while(left<right)
                {
                    Min=min(Min,arr[left+1]);
                    left++;
                }
                return Min;
            }
        }
    }
};
*/
class MinValue {
public:
    int getMin(vector<int> arr, int n) {
        // write code here
        if(n==0)
             return -1;
        if(n==1)
             return arr[0];
        int l=0;
        int r=n-1;
        if(arr[l]<arr[r])
            return arr[l];
        while(l<r)
        {
            if(r-l==1)
                return arr[r];
            int mid=(l+r)/2;
            if(arr[l]>arr[mid])
                r=mid;
            else if(arr[l]<arr[mid])
                l=mid;
            else
                l=mid;
        }
        return arr[r];
    }
};