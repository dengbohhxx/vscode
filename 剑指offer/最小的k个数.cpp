/*；利用快排思想
class Solution {
public:
    int partation(vector<int>&input,int start,int end)
    {
        int i=start;
        int j=end;
        int key=input[start];
        while(i<j)
        {
            while(i<j&&input[j]>=key)
                j--;
            while(i<j&&input[i]<=key)
                i++;
            if(i<j)
                swap(input[i],input[j]);
        }
        input[start]=input[i];
        input[i]=key;
        return i;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> vec;
        if(input.size()==0||k<=0||k>input.size())
            return vec;
        if(k==input.size())
        {
            vector<int> v(input.begin(),input.end());
            return v;
        }
        int start=0;
        int end=input.size()-1;
        int index=partation(input,start,end);
        while(index!=k-1)
        {
            if(index>k-1)
            {
                end=index-1;
                index=partation(input,start,end);
            }
            else
            {
                start=index+1;
                index=partation(input,start,end);
            }
        }
        for(int i=0;i<k;i++)
        {
            vec.push_back(input[i]);
        }
        return vec;
    }
};*/ 
class Solution {
public:
    /*堆排序递归和非递归版本
    int parttation(vector<int> &input,int start,int end)
    {
        int i=start;
        int j=end;
        int key=input[start];
        while(i<j)
        {
            while(i<j && input[j]>=key)
               j--;
            swap(input[i],input[j]);
            while(i<j && input[i]<=key)
               i++;
            swap(input[i],input[j]);
        }
        return i;
    }
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        
        vector<int> output;
        if(k<=0||input.empty()||k>input.size())
            return output;
        int start=0;
        int end=input.size()-1;
        int index=parttation(input,start,end);
        while(index!=k-1)
        {
            if(index>k-1)
            {
                end=index-1;
                index=parttation(input,start,end);
            }
            else
            {
                start=index+1;
                index=parttation(input,start,end);
            }
        }
        for(int i=0;i<k;i++)
        {
            output.push_back(input[i]);
        }
        return output;
    }*/
    void adjust(vector<int> & A, int len, int index)//非递归
	{
     
	 int maxidx = index;
        while(index<len)
        {
            int left = 2 * index + 1;//左
	        int right = 2 * index + 2;//右
            if (left<len && A[left]>A[maxidx])
	                maxidx = left;
	        if (right<len && A[right]>A[maxidx])
	               maxidx = right;//maxidx为最大的下标
            if(maxidx != index)
            {
                swap(A[maxidx], A[index]);
                index=maxidx;
            }
            else 
                break;
        }
	}
     vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
     {
         int size=input.size();
         vector<int> out;
         if(k<=0||k>size||input.empty())
             return out;
         for(int i=0;i<k;i++)
         {
             out.push_back(input[i]);
         }
         
         for(int i=k/2-1;i>=0;i--)
         {
             adjust(out,k,i);
         }
         
         for(int i=k;i<size;i++)
         {
             if(out[0]<=input[i])
                continue;
             else
             {
                 swap(out[0],input[i]);
                 adjust(out,k,0);
             }
         }
         
         return out;
     }
};