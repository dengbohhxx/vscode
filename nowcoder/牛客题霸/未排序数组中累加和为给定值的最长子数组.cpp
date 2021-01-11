#include<unordered_map>
class Solution {
public:
    /**
     * max length of the subarray sum = k
     * @param arr int整型vector the array
     * @param k int整型 target
     * @return int整型
     */
    int maxlenEqualK(vector<int>& arr, int k) {
        // write code here
        int n=arr.size();
        if(n==0)
            return 0;
        unordered_map<int,int> hash;
        hash[0]=-1;
        int len=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(hash.count(sum-k)>0)
            {
                len=max(len,i-hash[sum-k]);
            }
            if(hash.count(sum)==0)
            {
                hash[sum]=i;
            }
        }
        return len;
    }
};