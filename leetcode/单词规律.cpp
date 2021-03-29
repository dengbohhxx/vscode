class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> hash;
        unordered_map<string,char> hash1;
        int m=pattern.size();
        s+=" ";
        vector<string> vec;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                vec.push_back(s.substr(k,i-k));
                k=i+1;
            }
        }
        int n=vec.size();
        if(m!=n)
            return false;
        for(int i=0;i<m;i++)
        {
            if(hash.count(pattern[i])>0)
            {
                if(hash[pattern[i]]!=vec[i])
                {
                    return false;
                }
            }
            hash[pattern[i]]=vec[i];
        }
        for(int i=0;i<m;i++)
        {
            if(hash1.count(vec[i])>0)
            {
                if(hash1[vec[i]]!=pattern[i])
                {
                    return false;
                }
            }
            hash1[vec[i]]=pattern[i];
        }
        return true;
    }
};