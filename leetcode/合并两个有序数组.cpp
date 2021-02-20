class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            if(n==0)
                return;
            int idx=m+n-1;
            m=m-1;
            n=n-1;
            while(m>=0&&n>=0)
            {
                if(nums1[m]>=nums2[n])
                {
                    nums1[idx]=nums1[m];
                    m--;
                }
                else
                {
                    nums1[idx]=nums2[n];
                    n--;
                }
                idx--;
            }
            if(m>=0)
            {
                return;
            }
            if(n>=0)
            {
                while(n>=0)
                {
                    nums1[idx]=nums2[n];
                    idx--;
                    n--;
                }
                return;
            }

    }
};