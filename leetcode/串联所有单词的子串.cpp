class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n=s.size();
        int m=words.size();
        vector<int> vec;
        if(n==0||m==0)
            return vec;
        int wordlen=words[0].size();
        unordered_map<string,int> window;
        unordered_map<string,int> need;
        for(int i=0;i<m;i++)
        {
            need[words[i]]++;
        }
        for(int i=0;i<wordlen;i++)
        {
            int l=i;
            int r=i;
            int count=0;
            while(r+wordlen<=n)
            {
                string str=s.substr(r,wordlen);
                r+=wordlen;
                if(need.count(str)>0)
                {
                    window[str]++;
                    count++;
                    while(window[str]>need[str])
                    {
                        string temp=s.substr(l,wordlen);
                        l+=wordlen;
                        count--;
                        window[temp]--;
                    }
                    if(count==m)
                    {
                        vec.push_back(l);
                    }
                }
                else
                {
                    l=r;
                    count=0;
                    window.clear();
                }
            }
            window.clear();
        }
        return vec;
    }
};