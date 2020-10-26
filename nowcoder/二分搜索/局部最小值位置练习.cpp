class Solution {
public:
    int getpos(vector<int> arr,int left,int right)
    {
        while(left<right)
        {
            int mid =left+(right-left)/2;
            if(arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1])
                return mid;
            else if(arr[mid]>arr[mid-1])
               right=mid;
            else if(arr[mid]>arr[mid+1])
               left=mid;
            
                
        }
        return -1;
        
        
    }
    int getLessIndex(vector<int> arr) {
        int n=arr.size();
        if(n==0)
            return -1;
        if(n==1)
            return 0;
        if(arr[0]<arr[1])
            return 0;
        else if(arr[n-1]<arr[n-2])
            return n-1;
        else
        {
            int p=getpos(arr,0,n-1);
            return p;
        }
    }
};