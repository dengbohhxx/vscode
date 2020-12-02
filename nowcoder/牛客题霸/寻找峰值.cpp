class Solution {
public:
    /**
     * 寻找最后的山峰
     * @param a int整型一维数组 
     * @param aLen int a数组长度
     * @return int整型
     */
    int solve(int* a, int aLen) {
        // write code here
        if(aLen==0)
            return -1;
        if(aLen==1)
            return 0;
        for(int i=aLen-1;i>=0;i--)
        {
            if(i==aLen-1)
            {
                if(a[i]>=a[i-1])
                    return i;
            }
            else if(i==0)
            {
                if(a[i]>=a[i+1])
                    return 0;
            }
            else
            {
                if(a[i]>=a[i-1]&&a[i]>=a[i+1])
                    return i;
            }
        }
        return -1;
    }
};