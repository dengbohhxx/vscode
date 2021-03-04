class Solution {
public:
    int mySqrt(int x) {
        if(x==0)    
            return 0;
        int l=0;
        int r=x;
        int res=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if((long long)mid*mid<x)
            {
                res=mid;
                l=mid+1;
            }
            else if((long long)mid*mid==x)
            {
                return mid;
            }
            else
            {
                r=mid-1;
            }
        }
        return res;
    }
};