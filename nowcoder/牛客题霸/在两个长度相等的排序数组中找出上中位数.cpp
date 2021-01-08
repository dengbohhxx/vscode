class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int getmid(vector<int> arr1,int start1,int end1, vector<int> arr2,int start2,int end2)
    {
        if(start1==end1)
        {
            return min(arr1[start1],arr2[start2]);
        }
        int size=end1-start1+1;
        int halfsize=0;
        if(size%2==0)
        {
            halfsize=size/2;
        }
        else
        {
            halfsize=(size+1)/2;
        }
        if(arr1[start1+halfsize-1]==arr2[start2+halfsize-1])
            return arr1[start1+halfsize-1];
        else if(arr1[start1+halfsize-1]<arr2[start2+halfsize-1])
            return getmid(arr1,end1-(halfsize-1),end1,arr2,start2,start2+halfsize-1);
        else
            return getmid(arr1,start1,start1+halfsize-1,arr2,end2-(halfsize-1),end2);
    }
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        int len1=arr1.size();
        int len2=arr2.size();
        if(len1==0||len2==0)
            return -1;
        if(len1!=len2)
            return -1;
        return getmid(arr1,0,len1-1,arr2,0,len2-1);
    }
};