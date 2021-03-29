class Solution {
public:
    int getdigit()
    {
        int ret=0;
        while (ptr < src.size() && isdigit(src[ptr]))
        {
            ret=ret*10+src[ptr]-'0';
            ptr++;
        }
        return ret;
    }
    string getstring()
    {
        if(ptr==src.size()||src[ptr]==']')
            return "";
        char cur=src[ptr];
        int reptime=1;
        string ret;
        if(isdigit(cur))
        {
            reptime=getdigit();
            ptr++;
            string str=getstring();
            ptr++;
            while(reptime--)
            {
                ret+=str;
            }
        }
        else if(isalpha(cur))
        {
            ret=string(1,cur);
            ptr++;
        }
        return ret+getstring();
    }
    string decodeString(string s) {
        src=s;
        ptr=0;
        string str=getstring();
        return str;
    }
private:
    string src;
    int ptr;
};