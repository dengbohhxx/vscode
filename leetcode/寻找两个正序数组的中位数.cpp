class Solution {
public:
    int getkthelement(vector<int>& nums1, vector<int>& nums2,int k)
    {
        int m=nums1.size();
        int n=nums2.size();
        int index1=0;
        int index2=0;
        while(1)
        {
            if(index1==m)
            {
                return nums2[index2+k-1];
            }
            if(index2==n)
            {
                return nums1[index1+k-1];
            }
            if(k==1)
            {
                return min(nums1[index1],nums2[index2]);
            }

            int newindex1=min(index1+k/2-1,m-1);
            int newindex2=min(index2+k/2-1,n-1);
            if(nums1[newindex1]<=nums2[newindex2])
            {
                k -= newindex1 - index1 + 1;
                index1=newindex1+1;
            }
            else
            {
                k -= newindex2 - index2 + 1;
                index2=newindex2+1;
            }
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len=nums1.size()+nums2.size();
        if(len%2==1)
            return getkthelement(nums1,nums2,(len+1)/2);
        else
            return (getkthelement(nums1,nums2,len/2)+getkthelement(nums1,nums2,len/2+1))/2.0;
    }
};