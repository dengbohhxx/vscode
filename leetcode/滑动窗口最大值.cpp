class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> vec;
        if(k<1)
        return vec;
        if(nums.size()<=k)
        {
            vec.push_back(*max_element(nums.begin(),nums.end()));
            return vec;
        }
        deque<int> deq;
        for(int i=0;i<nums.size();i++)
        {
            while(!deq.empty()&&nums[i]>=nums[deq.back()])
                    deq.pop_back();
            deq.push_back(i);
            if(!deq.empty()&&deq.front()==i-k)
                    deq.pop_front();
            if(i>=k-1)
            {
                vec.push_back(nums[deq.front()]);
            }
        }
        return vec;
    }
};