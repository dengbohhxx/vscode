class Solution {
public:
    /*
    int partation(vector<int> &numbers,int start ,int end)
    {
        int i=start;
        int j=end;
        int key=numbers[start];
        while(i<j)
        {
            while(i<j && numbers[j]>=key)
                j--;
            swap(numbers[i],numbers[j]);
            while(i<j && numbers[i]<=key)
                i++;
            swap(numbers[i],numbers[j]);
        }
        return i;
    }
    bool morethanhalf(vector<int> &numbers,int target)
    {
        bool res=false;
        int times=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(numbers[i]==target)
                times++;
        }
        if(times*2>numbers.size())
            res=true;
        return res;
    }
    
    int MoreThanHalfNum_Solution(vector<int> numbers) {
     
        if(numbers.empty())
            return 0;
        int size=numbers.size();
        int start=0;
        int end=size-1;
        int mid=size/2;
        int index=partation(numbers,start,end);
        while(index!=mid)
        {
            if(index>mid)
            {
                end=index-1;
                index=partation(numbers,start,end);
            }
            else
            {
                start=index+1;
                index=partation(numbers,start,end);
            }
        }
        int result=numbers[mid];
        if(!morethanhalf(numbers,result))
            result=0;
        return result;
        */
    bool morethanhalf(vector<int> &numbers,int target)
    {
        bool res=false;
        int times=0;
        for(int i=0;i<numbers.size();i++)
        {
            if(numbers[i]==target)
                times++;
        }
        if(times*2>numbers.size())
            res=true;
        return res;
    }
    int MoreThanHalfNum_Solution(vector<int> numbers)
    {
         if(numbers.empty())
            return 0;
        int result=numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++)
        {
            if(numbers[i]==result)
            {
                count++;
            }
            else
            {
                count--;
            }
            if(count==0)
            {
                result=numbers[i];
                count=1;
            }
            
            
        }
        if(!morethanhalf(numbers,result))
            result=0;
        return result;
    }
};