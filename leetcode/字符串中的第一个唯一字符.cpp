class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        if(n==0)
        {
            return -1;
        }
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[s[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(hash[s[i]]==1)
                return i;
        }
        return -1;
    }
};