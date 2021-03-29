class Solution {
public:
    char findTheDifference(string s, string t) {
        int n=s.size();
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[s[i]]++;
        }
        int m=t.size();
        char c;
        for(int i=0;i<m;i++)
        {
            hash[t[i]]--;
            if(hash[t[i]]<0)
            {
                c=t[i];
                break;
            }
        }
        return c;
    }
};