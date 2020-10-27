class Find {
public:
    int findPos(vector<int> arr, int n) {
        // write code here
        int left=0;
        int right=n-1;
        int mid=0;
        int res=-1;
        if(arr[0]>n-1)
            return res;
        if(arr[n-1]<0)
            return res;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(arr[mid]==mid)
            {
                res=mid;
                right=mid-1;
            }
            else if(arr[mid]>mid)
            {
                right=mid-1;
            }
            else if(arr[mid]<mid)
            {
                left=mid+1;
            }
            
        }
        return res;
        
    }
};