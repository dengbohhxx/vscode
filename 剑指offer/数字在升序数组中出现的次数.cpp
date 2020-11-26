class Solution {
public:
    int getfirstk(vector<int> &data ,int k)
    {
        int res=-1;
        int left=0;
        int right=data.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(data[mid]>k)
            {
                right=mid-1;
            }
            else if(data[mid]<k)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
                res=mid;
            }
        }
        return res;
    }
    int getlastk(vector<int> &data ,int k)
    {
        int res=-1;
        int left=0;
        int right=data.size()-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(data[mid]>k)
            {
                right=mid-1;
            }
            else if(data[mid]<k)
            {
                left=mid+1;
            }
            else
            {
                left=mid+1;
                res=mid;
            }
        }
        return res;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        int n=data.size();
        if(n==0)
            return 0;
        int first=getfirstk(data ,k);
        int last=getlastk(data ,k);
        if(first==-1||last==-1)
            return 0;
        return last-first+1;
    }
};