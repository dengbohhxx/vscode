class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> need,window;
        for(int i=0;i<s1.size();i++)
        {
            need[s1[i]]++;
        }
        int left=0;int right=0;
        int start=0;
        int len=INT_MAX;
        int valid=0;
        while(right<s2.size())
        {
            char c=s2[right];
            right++;
            if(need.count(c)>0)
            {
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            while(right-left>=s1.size())
            {
                if(valid==need.size())
                {
                    return true;
                }
                char d=s2[left];
                left++;
                if(need.count(d)>0)
                {
                    if(need[d]==window[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return false;     
    }
};