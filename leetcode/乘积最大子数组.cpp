class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return nums[0];
        vector<int> dpmax(n,0);
        vector<int> dpmin(n,0);
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            int cur=nums[i];
            if(cur==0)
            {
                dpmax[i]=0;
                dpmin[i]=0;
            }
            else if(cur>0)
            {
                dpmax[i]=max(cur,cur*dpmax[i-1]);
                dpmin[i]=min(cur,cur*dpmin[i-1]);
            }
            else if(cur<0)
            {
                dpmax[i]=max(cur,cur*dpmin[i-1]);
                dpmin[i]=min(cur,cur*dpmax[i-1]);
            }
        }
        return *max_element(dpmax.begin(),dpmax.end());
    }
};