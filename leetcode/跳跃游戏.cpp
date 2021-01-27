class Solution {
public:
    bool canJump(vector<int>& nums) {
            int n=nums.size();
            int maxpos=0;
            for(int i=0;i<n;i++)
            {
                if(maxpos>=i)
                {
                    maxpos=max(maxpos,nums[i]+i);
                    if(maxpos>=n-1)
                        return true;
                }
            }
            return false;
    }
};