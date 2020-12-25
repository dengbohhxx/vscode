class Solution {
public:
    /**
     * return the min number
     * @param arr int整型vector the array
     * @return int整型
     */
    int minNumberdisappered(vector<int>& arr) {
        // write code here
        //最小正整数只能在 [1,N+1] 中
        int n=arr.size();
        for(int i=0;i<n;i++)//将数组中负数转化为n+1
        {
            if(arr[i]<=0)
            {
                arr[i]=n+1;
            }
        }
        //将小于n位置的数字打标机，记为负数
        for(int i=0;i<n;i++)
        {
            int num=arr[i];
            if(num<=n)
            {
                arr[num-1]=-1*arr[num-1];
            }
        }
        //第一个未标记（正数）的位置i+1即为数组中未出现的最小正整数
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
                return i+1;
        }
        
        return n+1;
    }
};