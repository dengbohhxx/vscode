class Solution {
public:
    /**
     * 二分查找
     * @param n int整型 数组长度
     * @param v int整型 查找值
     * @param a int整型vector 有序数组
     * @return int整型
     */
    int ub(vector<int>& a,int v,int start,int end)
    {
        int res=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(a[mid]>=v)
            {
                res=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return res+1;
    }
    int upper_bound_(int n, int v, vector<int>& a) {
        // write code here
        if(v>a[n-1])
            return n+1;
        int res=ub(a,v,0,n-1);
        return res;
    }
};