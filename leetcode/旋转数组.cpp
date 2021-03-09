class Solution {
public:
    void swap(vector<int>& nums,int l,int r)
    {
        while(l<r)
        {
            ::swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0||n==1)
            return;
        k=k%n;
        reverse(nums.begin(),nums.end());
        swap(nums,0,k-1);
        swap(nums,k,n-1);
    }
};