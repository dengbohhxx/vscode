class LeftMostAppearance {
public:
    int findPos(vector<int> arr, int n, int num) {
        // write code here
        int res=-1;//位置初始化为-1
        int left=0;
        int right=n-1;
        int mid=0;
        //最左的位置都是left<=right,二分改变区间时不包含mid值
        while(left<=right)
        {
            mid=(left+right)/2;
            if(arr[mid]<num)
                left=mid+1;//改变区间时不包含mid
            if(arr[mid]>num)
                right=mid-1;
            if(arr[mid]==num)
            {
                right=mid-1;//因为是找最左
                res=mid;//
            }
        }
        return res;
    }
};