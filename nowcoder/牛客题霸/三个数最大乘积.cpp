class Solution {
public:
    /**
     * 最大乘积
     * @param A int整型一维数组 
     * @param ALen int A数组长度
     * @return long长整型
     long long solve(int* A, int ALen) {
        // write code here
        sort(A,A+ALen);
        long long val1=A[0]*A[1]*A[ALen-1];
        long long val3=A[ALen-1]*A[ALen-2]*A[ALen-3];
        return max(val1,val3);
     */
    long long solve(int* A, int ALen) {
        // write code here
        long long max1=INT_MIN;
        long long max2=INT_MIN;
        long long max3=INT_MIN;
        long long min1=INT_MAX;
        long long min2=INT_MAX;
        for(int i=0;i<ALen;i++)
        {
            if(A[i]<=min1)
            {
                min2=min1;
                min1=A[i];
            }
            else if(A[i]<=min2)
            {
                min2=A[i];
            }
            
            if(A[i]>=max1)
            {
                max3=max2;
                max2=max1;
                max1=A[i];
            }
            else if(A[i]>=max2)
            {
                max3=max2;
                max2=A[i];
            }
            else if(A[i]>=max3)
            {
                max3=A[i];
            }
        }
        return max(max1*max2*max3,min1*min2*max1);
    }
};