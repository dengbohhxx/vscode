class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        vector<int> vec;
        if(n1==0||n2==0)
            return vec;
        unordered_map<int,int> hash;
        for(int i=0;i<n1;i++)
        {
            hash[nums1[i]]++;
        }
        set<int> s;
        for(int i=0;i<n2;i++)
        {
            s.insert(nums2[i]);
        }
        for(set<int>::iterator iter=s.begin();iter!=s.end();iter++)
        {
            if(hash.count(*iter)>0)
            {
                vec.push_back(*iter);
            }
        }
        return vec;
    }
};