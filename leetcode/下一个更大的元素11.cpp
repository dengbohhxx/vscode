class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> vec(n);
        stack<int> sta;
        for(int i=2*n-1;i>=0;i--)
        {
            while(!sta.empty()&&nums[i%n]>=sta.top())
                            sta.pop();
            vec[i%n]=sta.empty()?-1:sta.top();
            sta.push(nums[i%n]);
        }
        return vec;
    }
};