class Solution {
public:
    int getmax(vector<int> piles)
    {
        int max1=0;
        for(int i=0;i<piles.size();i++)
        {
            max1=max(max1,piles[i]);
        }
        return max1;
    }
    int timeof(int n,int speed)
    {
        return (n/speed)+((n%speed>0)?1:0);
    }
    bool canfinish(vector<int> piles,int k,int H)
    {
        int time=0;
        for(int i=0;i<piles.size();i++)
        {
            time+=timeof(piles[i],k);
        }
        return time<=H;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
            int left=1;
            int right=getmax(piles);
            while(left<=right)
            {
                int mid=(left+right)/2;
                if(canfinish(piles,mid,H))
                {
                    right=mid-1;
                }
                else
                {
                    left=mid+1;
                }
            }
            if(left>getmax(piles))
                return  -1;
            return left;
    }
};