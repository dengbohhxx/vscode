/*
class Solution {
public://暴力搜索
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        if(n==0)
            return res;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]+nums[j]==target)
                    {
                        res.push_back(j);
                        res.push_back(i);
                        break;
                    }
            }
        }
        return res;
    }
};
class Solution {
public://哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> res;
        int n=nums.size();
        if(n==0)
            return res;
        for(int i=0;i<n;i++)
        {
            if(hash.count(target-nums[i])>0)
            {
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
                break;
            }
            if(hash.count(nums[i])==0)
            {
                hash[nums[i]]=i;
            }
        }
        return res;

    }
};
class Solution {
public:
//由于返回的是下标，因此不能用排序+双指针，如果是返回和为target的两个数字，则可以用排序+双指针
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> res;
        if(n==0)
            return res;
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        while(low<high)
        {
            int sum=nums[low]+nums[high];
            if(sum<target)
            {
                low++;
            }
            if(sum>target)
            {
                high--;
            }
            else
            {
                res.push_back(low);
                res.push_back(high);
                break;
            }
        }
        return res;
    }
};
*/

class Solution {
public:
//哈希表
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        vector<int> res;
        int n=nums.size();
        if(n==0)
            return res;
        for(int i=0;i<n;i++)
        {
            if(hash.count(target-nums[i])>0)
            {
                res.push_back(hash[target-nums[i]]);
                res.push_back(i);
                break;
            }
            if(hash.count(nums[i])==0)
            {
                hash[nums[i]]=i;
            }
        }
        return res;

    }
};