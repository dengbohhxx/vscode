class Solution {
public:
    bool isdanci(string s)
    {
        int n=s.size();
        if(n==0)
            return false;
        for(int i=0;i<s.size();i++)
        {
            if(!isalpha(s[i]))
            {
                return false;
            }
        }
        return true;
    }
    int lengthOfLastWord(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        s+=" ";
        vector<string> vec;
        string str;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                str+=s[i];
            }
            else
            {
                vec.push_back(str);
                str.clear();
            }
        }
        for(int i=vec.size()-1;i>=0;i--)
        {
            if(isdanci(vec[i]))
            {
                return vec[i].size();
            }
        }
        return 0;
    }
};