/*堆排序 循环
    void adjust(vector<int>& nums,int len,int index)
    {
        int maxidx=index;
        while(index<len)
        {
            int l=2*index+1;
            int r=2*index+2;
            if(l<len&&nums[l]>=nums[maxidx])
            {
                maxidx=l;
            }
            if(r<len&&nums[r]>=nums[maxidx])
            {
                maxidx=r;
            }
            if(maxidx!=index)
            {
                swap(nums[index],nums[maxidx]);
                index=maxidx;
            }
            else
            {
                break;
            }
        }
    }
    //堆排序 递归
     void adjust(vector<int>& nums,int len,int index)
    {
        int maxidx=index;
        int l=2*index+1;
        int r=2*index+2;
        if(l<len&&nums[l]>=nums[maxidx])
        {
            maxidx=l;
        }
        if(r<len&&nums[r]>=nums[maxidx])
        {
             maxidx=r;
        }
        if(maxidx!=index)
        {
            swap(nums[index],nums[maxidx]);
            adjust(nums,len,maxidx);
        }
    }
     vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return nums;
        for(int i=n/2-1 ;i>=0;i--)
        {
            adjust(nums,n,i);
        }
        for(int i=n-1;i>0;i--)
        {
            swap(nums[0],nums[i]);
            adjust(nums,i,0);
        }
        return nums;
    }
    class Solution {
public://快速排序
    int partation(vector<int>& nums,int start,int end)
    {
        int i=start;
        int j=end;
        int key=nums[i];
        while(i<j)
        {
            while(i<j&&nums[j]>=key)
                j--;
            while(i<j&&nums[i]<=key)
                i++;
            if(i<j)
                swap(nums[i],nums[j]);
        }
        nums[start]=nums[i];
        nums[i]=key;
        return i;
    }
    void qsort(vector<int>& nums,int start,int end)
    {
        if(start>end)
        {
            return;
        }
        int j=partation(nums,start,end);
        qsort(nums,start,j-1);
        qsort(nums,j+1,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return nums;
        qsort(nums,0,n-1);
        return nums;
    }
};
    */
class Solution {
public:
    //归并排序
    void merge(vector<int>& nums,int start,int mid,int end)
    {
        vector<int> temp(end-start+1,0);
        for(int i=start;i<=end;i++)
        {
            temp[i-start]=nums[i];
        }
        int i=start;
        int j=mid+1;
        for(int k=start;k<=end;k++)
        {
            if(i>mid)
            {
                nums[k]=temp[j-start];
                j++;
            }
            else  if(j>end)
            {
                nums[k]=temp[i-start];
                i++;
            }
            else if(temp[i-start]<=temp[j-start])
            {
                nums[k]=temp[i-start];
                i++;
            }
            else if(temp[i-start]>temp[j-start])
            {
                nums[k]=temp[j-start];
                j++;
            }
        }
    }
    void mergesort(vector<int>& nums,int start,int end)
    {
        if(start>=end)
        {
            return;
        }
        int mid=(start+end)/2;
        mergesort(nums,start,mid);
        mergesort(nums,mid+1,end);
        merge(nums,start,mid,end);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return nums;
        mergesort(nums,0,n-1);
        return nums;
    }
};