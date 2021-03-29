class Solution {
public:
    Solution(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back(nums[i]);
            vec1.push_back(nums[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        vec=vec1;
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(vec.begin(),vec.end());
        return vec;
    }
private:
    vector<int> vec;
    vector<int> vec1;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */