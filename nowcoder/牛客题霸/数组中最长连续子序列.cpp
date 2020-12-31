class Solution {
public:
    /**
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
    int MLS(vector<int>& arr) {
        // write code here
        sort(arr.begin(),arr.end());
        int max1=INT_MIN;
        int len=1;
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i]-1==arr[i-1])
                len++;
            else if(arr[i]!=arr[i-1])//arr[i]!=arr[i-1]还有可能是是连续升序，因此要跳过看下一个
            {
                len=1;
            }
            max1=max(max1,len);
        }
        return max1;
    }
};