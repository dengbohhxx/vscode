class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums intvector 
     * @return intvector<vector<>>
     */
    vector<int> rightmin(vector<int>& nums)
    {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n,0);
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty()&&nums[i]<=nums[s.top()])
            {
                s.pop();
            }
            ans[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<int> leftmin(vector<int>& nums)
    {
        int n=nums.size();
        stack<int> s;
        vector<int> ans(n,0);
        for(int i=0;i<n;i++)
        {
            while(!s.empty()&&nums[i]<=nums[s.top()])
            {
                s.pop();
            }
            ans[i]=s.empty()?-1:s.top();
            s.push(i);
        }
        return ans;
    }
    vector<vector<int> > foundMonotoneStack(vector<int>& nums) {
        // write code here
        vector<vector<int> > res;
        int n=nums.size();
        if(n==0)
            return res; 
        vector<int> rm=rightmin(nums);
        vector<int> lm=leftmin(nums);
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            temp.push_back(lm[i]);
            temp.push_back(rm[i]);
            res.push_back(temp);
        }
        return res;
    }
};