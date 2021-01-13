class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(int i=0;i<t.size();i++)
        {
            need[t[i]]++;
        }
        int left=0;int right=0;
        int start=0;
        int len=INT_MAX;
        int valid=0;
        while(right<s.size())
        {
            char c=s[right];
            right++;
            if(need.count(c)>0)
            {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            while(valid==need.size())
            {
                if(right-left<len)
                {
                    start=left;
                    len=right-left;//由于right++在满足valid==need.size()后还进行了++，所以len=right-left,而不是普通的right-left+1
                }
                char d=s[left];
                left++;
                if(need.count(d)>0)
                {
                    if(need[d]==window[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return len==INT_MAX?"":s.substr(start,len);             
    }                 
};