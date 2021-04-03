class Solution {
public:
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
            else if(j>end)
            {
                nums[k]=temp[i-start];
                res+=(j - (mid + 1));
                i++;
            }
            else if(temp[i-start]<=temp[j-start])
            {
                nums[k]=temp[i-start];
                res+=(j - (mid + 1));
                i++;
            }
            else
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
    int reversePairs(vector<int>& nums) {
        res=0;
        int n=nums.size();
        if(n==0)
            return 0;
        mergesort(nums,0,n-1);
        return res;
    }
private:
    int res;
};