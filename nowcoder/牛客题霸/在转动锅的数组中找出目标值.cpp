class Solution {
public:
    /**
     * 
     * @param A int整型一维数组 
     * @param n int A数组长度
     * @param target int整型 
     * @return int整型
     */
    int searching(int* A,int start,int end,int tar)
    {
        int res=-1;
        while(start<=end)
        {
            int mid=(start+end)/2;
            if(A[mid]==tar)
            {
                res=mid;
                break;
            }
            if(A[mid]>=A[start])
            {
                if(A[mid]>tar&&A[start]<=tar)
                    end=mid-1;
                else
                    start=mid+1;
            }
            if(A[mid]<=A[end])
            {
                if(A[mid]<tar&&A[end]>=tar)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return res;
    }
    int search(int* A, int n, int target) {
        // write code here
        if(A==NULL||n==0)
            return 0;
        int k=searching(A,0,n-1,target);
        return k;
    }
};