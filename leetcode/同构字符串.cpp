class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int  m=s.size();
        int n=t.size();
        if(m!=n)
            return false;
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;
        for(int i=0;i<m;i++)
        {
            char x=s[i];
            char y=t[i];
            if((s2t.count(x)>0&&s2t[x]!=y)||(t2s.count(y)>0&&t2s[y]!=x))
            {
                return false;
            }
            s2t[x]=y;
            t2s[y]=x;
        }
        return true;
    }
};