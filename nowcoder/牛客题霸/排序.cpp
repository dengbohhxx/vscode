class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    int partation(vector<int>& arr,int start,int end)
    {
        int key=arr[start];
        int i=start;
        int j=end;
        while(i<j)
        {
            while(i<j&&arr[j]>=key)
                j--;
            while(i<j&&arr[i]<=key)
                i++;
            if(i<j)
                swap(arr[i],arr[j]);
        }
        arr[start]=arr[i];
        arr[i]=key;
        return i;
    }
    void qsort(vector<int>& arr,int start,int end)
    {
        if(start>=end)
            return;
        else
        {
            int j=partation(arr,start,end);
            qsort(arr,start,j-1);
            qsort(arr,j+1,end);
        }
    }
    vector<int> MySort(vector<int>& arr) {
        // write code here
        int n=arr.size();
        qsort(arr,0,n-1);
        return arr;
    }
};