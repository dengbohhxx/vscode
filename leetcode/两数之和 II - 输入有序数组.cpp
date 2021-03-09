class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vec;
        int n=numbers.size();
        if(n==0)
            return vec;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            if(numbers[l]+numbers[r]==target)
                {
                    vec.push_back(l+1);
                    vec.push_back(r+1);
                    break;
                }
            else if(numbers[l]+numbers[r]>target)
            {
                r--;
            }
            else if(numbers[l]+numbers[r]<target)
            {
                l++;
            }
        }
        return vec;
    }
};