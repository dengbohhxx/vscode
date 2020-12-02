class Solution {
public:
    /**
     * 最大数
     * @param nums int整型vector 
     * @return string字符串
     */
    string solve(vector<int>& nums) {
        // write code here
        string str;
        int size=nums.size();
        if(size==0)
            return str;
        if(size==1)
            return to_string(nums[0]);
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(to_string(nums[i])+to_string(nums[j])<=to_string(nums[j])+to_string(nums[i]))
                    swap(nums[i],nums[j]);
            }
        }
        
        for(int i=0;i<size;i++)
            str+=to_string(nums[i]);
        while(str.size()>1&&str[0]=='0')
            str.erase(str.begin());
        return str;
    }
};