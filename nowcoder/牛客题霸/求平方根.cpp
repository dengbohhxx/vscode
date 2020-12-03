class Solution {
public:
    /**
     * 
     * @param x int整型 
     * @return int整型
     */
    int sqrt(int x) {
        // write code here
        if(x<=0)
            return 0;
        long left=1;
        long right=x/2+1;
        while(right-left>0.2)
        {
            long mid=left+(right-left)/2;
            if(mid<=x/mid&&(mid+1)>x/(mid+1))
            {
                return (int)mid;
            }
            else if(mid<x/mid)
                left=mid+1;
            else 
                right=mid-1;
        }
        return (int)left;
    }
};