class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
          int n1=nums1.size();
        int n2=nums2.size();
        vector<int> vec;
        if(n1==0||n2==0)
            return vec;
        unordered_map<int,int> hash;
        if(n1>=n2)
        {
            for(int i=0;i<n1;i++)
            {
                hash[nums1[i]]++;
            }
            for(int i=0;i<n2;i++)
            {
                if(hash[nums2[i]]>0)
                {
                    hash[nums2[i]]--;
                    vec.push_back(nums2[i]);
                }
            }
        }
        else
        {
             for(int i=0;i<n2;i++)
                {
                    hash[nums2[i]]++;
                }
            for(int i=0;i<n1;i++)
             {
                    if(hash[nums1[i]]>0)
                    {
                        hash[nums1[i]]--;
                        vec.push_back(nums1[i]);
                    }
            }
        }
        return vec;
    }
};