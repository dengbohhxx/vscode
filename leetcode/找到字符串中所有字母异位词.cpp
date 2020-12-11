class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
            int start=0;
            int match=0;
            vector<int> vec;
            int left=0;
            int right=0;
            unordered_map<char,int> window;
            unordered_map<char,int> need;
            for(int i=0;i<p.size();i++)
                need[p[i]]++;
            while(right<s.size())
            {
                char c1=s[right];
                if(need.count(c1)>0)
                {
                    window[c1]++;
                    if(window[c1]==need[c1])
                        match++;
                }
                right++;

                while(match==need.size())
                {
                    if(right-left==p.size())
                        vec.push_back(left);
                    char c2=s[left];
                    if(need.count(c2)>0)
                    {
                        window[c2]--;
                        if(window[c2]<need[c2])
                            match--;
                    }
                left++;
                }
            }
            return vec;
    }
};