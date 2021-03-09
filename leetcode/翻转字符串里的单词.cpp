class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> vec;
        if(s.size()==0)
            return s;
        s+=' ';
        int idx=0;
        int len=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=' ')
            {
                if(len==0)
                    idx=i;
                len++;
                if(s[i+1]==' ')
                {
                    string str=s.substr(idx,len);
                    vec.push_back(str);
                    len=0;
                }
            }
        }
        reverse(vec.begin(),vec.end());
        for(int i=0;i<vec.size();i++)
        {
            res+=vec[i];
            if(i!=vec.size()-1)
            res+=' ';
        }
        
        return res;
    }
};
