class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hash;//哈希表
        stack<int> sta;//单调栈
        for(int i=nums2.size()-1;i>=0;i--)
        {
            while(!sta.empty()&&nums2[i]>=sta.top())
                sta.pop();//nums2【i】大于栈顶元素 弹出
            hash[nums2[i]]=sta.empty()?-1:sta.top();//插入哈希表
            sta.push(nums2[i]);//压入栈
        }
        vector<int> vec;
        for(int i=0;i<nums1.size();i++)
        {
            vec.push_back(hash[nums1[i]]);
        }
        return vec;
    }
};