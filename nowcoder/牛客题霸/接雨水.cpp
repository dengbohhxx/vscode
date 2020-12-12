class Solution {
public:
    /**
     * max water
     * @param arr int整型vector the array
     * @return long长整型
     */
    long long maxWater(vector<int>& arr) {
        // write code here
        if(arr.empty())
            return 0;
        int n=arr.size();
        int left=0;
        int right=n-1;
        long long  res=0;
        int l_max=arr[0];
        int r_max=arr[n-1];
        while(left<=right)
        {
            l_max=max(arr[left],l_max);
            r_max=max(arr[right],r_max);
            if(l_max<r_max)
            {
                res+=l_max-arr[left];
                left++;
            }
            else
            {
                res+=r_max-arr[right];
                right--;
            }
        }
        return res;
    }
};