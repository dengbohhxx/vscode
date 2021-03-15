class Solution {
public:
    bool isyuanyin(char c)
    {
        unordered_map<char,int> hash;
        hash['a']++;
        hash['e']++;
        hash['i']++;
        hash['o']++;
        hash['u']++;
        hash['A']++;
        hash['E']++;
        hash['I']++;
         hash['O']++;
        hash['U']++;
        if(hash.count(c)>0)
            return true;
        return false;
    }
    string reverseVowels(string s) {
        int n=s.size();
        if(n==0||n==1)
            return s;
        int l=0;
        int r=n-1;
        while(l<r)
        {
            while(!isyuanyin(s[l])&&l<n-1)
            {
                l++;
            }
            while(!isyuanyin(s[r])&&r>0)
            {
                r--;
            }
            if(l>=r)
                break;
            swap(s[l],s[r]);
            l++;
            r--;
        }
        return s;
    }
};