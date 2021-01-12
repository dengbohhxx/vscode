/*
class Solution {
public:
    int partation(vector<int>& A,int start,int end)
    {//partation过程
        int i=start;
        int j=end;
        int key=A[start];
        while(i<j)
        {
            while(i<j&&A[j]>=key)
                j--;
            while(i<j&&A[i]<=key)
                i++;
            if(i<j)
                swap(A[i],A[j]);
        }
        A[start]=A[i];
        A[i]=key;
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
            int size=nums.size();
            if(size==0||k>size)
                return -1;
            int start=0;
            int end=size-1;
            int idx=partation(nums,start,end);
            while(idx!=size-k)
            {
                if(idx>size-k)
                {
                    end=idx-1;
                    idx=partation(nums,start,end);
                }
                else if(idx<size-k)
                {
                    start=idx+1;
                    idx=partation(nums,start,end);
                }
            }
            return nums[idx];
    }
};

class Solution {
public:
    void adjust(vector<int>& num,int index,int len)
    {//小根堆
        int minidx=index;
        while(index<len)
        {
            int left=2*index+1;
            int right=2*index+2;
            if(left<len&&num[left]<=num[minidx])
            {
                minidx=left;
            }
            if(right<len&&num[right]<=num[minidx])
            {
                minidx=right;
            }
            if(minidx!=index)
            {
                swap(num[minidx],num[index]);
                index=minidx;
            }
            else
            {
                break;
            }
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int i=0;
        vector<int> vec;
        int size=nums.size();
        if(size==0||k>size)
            return -1;
        while(i<k)
        {
            vec.push_back(nums[i]);
            i++;
        }
        int n=vec.size();
        for(int i=n/2-1;i>=0;i--)
        {
            adjust(vec,i,n);
        }
        for(int j=i;j<size;j++)
        {
            if(nums[j]<vec[0])
                continue;
            vec[0]=nums[j];
            adjust(vec,0,n);
        }
        return vec[0];
    }
};
*/
class Solution {
public:
//使用make_heap,push_heap,pop_heap
    int findKthLargest(vector<int>& nums, int k) {
        int i=0;
        vector<int> vec;
        int size=nums.size();
        if(size==0||k>size)
            return -1;
        while(i<k)
        {
            vec.push_back(nums[i]);
            i++;
        }
        int n=vec.size();
        make_heap(vec.begin(),vec.end(),greater<>());
        for(int j=i;j<size;j++)
        {
            if(nums[j]<vec[0])
                continue;
            pop_heap(vec.begin(),vec.end(),greater<>());
            vec.pop_back();
            vec.push_back(nums[j]);
            push_heap(vec.begin(),vec.end(),greater<>());
        }
        return vec[0];
    }
};