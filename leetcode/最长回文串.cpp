class Solution {
public:
    int longestPalindrome(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        unordered_map<char,int> hash;
        for(int i=0;i<n;i++)
        {
            hash[s[i]]++;
        }
        int res=0;
        for(unordered_map<char,int>::iterator iter=hash.begin();iter!=hash.end();iter++)
        {
            int dou=iter->second;
            res+=dou/2*2;
            if(dou%2==1&&res%2==0)
                res+=1;
        }
        return res;
    }
};