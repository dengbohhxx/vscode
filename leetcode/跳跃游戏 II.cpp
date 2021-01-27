class Solution {
public:
    int jump(vector<int>& nums) {
        int right=0;
        int step=0;
        int maxpos=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(maxpos>=i)
            {
                maxpos=max(maxpos,i+nums[i]);
                if(right==i)
                {
                    step++;
                    right=maxpos;
                }
            }
        }
        return step;
    }
};