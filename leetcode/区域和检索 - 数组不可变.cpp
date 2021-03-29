class NumArray {
public:
    NumArray(vector<int>& nums) {
        presum.push_back(0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            presum.push_back(presum[i]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return presum[right+1]-presum[left];
    }
private:
vector<int> presum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */