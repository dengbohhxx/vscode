class Solution {
public:
 int getmax(vector<int> weights)
    {
        int max1=0;
        for(int i=0;i<weights.size();i++)
        {
            max1=max(max1,weights[i]);
        }
        return max1;
    }
    int getsum(vector<int> weights)
    {
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
        }
        return sum;
    }
    bool canfinish(vector<int> weights,int D,int cap)
    {
        int i=0;
        for(int day=0;day<D;day++)
        {
            int maxcap=cap;
            while((maxcap-=weights[i])>=0)
            {
                i++;
                if(i==weights.size())
                    return true;
            }
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int D) {
        int left=getmax(weights);
        int right=getsum(weights);
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(canfinish(weights,D,mid))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        if(left>getsum(weights))
            return -1;
        return left;
    }
};