class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> hash;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            hash[arr[i]]++;
        }
        unordered_set<int> unset;
        for(unordered_map<int,int>::iterator iter=hash.begin();iter!=hash.end();iter++)
        {
            unset.insert(iter->second);
        }
        return unset.size()==hash.size();
    }
};