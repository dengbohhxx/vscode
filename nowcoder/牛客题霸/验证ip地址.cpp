class Solution {
public:
    /**
     * 验证IP地址
     * @param IP string字符串 一个IP地址字符串
     * @return string字符串
     */
    bool type(string &s)
    {
        for(size_t i=0;i<s.size();i++)
        {
            if(s[i]=='.')
                return true;
            if(s[i]==':')
                return false;
        }
        return false;
    }
    bool isvalidv4(string s)
    {
        if((s.size()>=1 && s[0]=='0')||s.size()>3)//判断是否失效
            return false;
        return stoi(s)<256;//还要小于255
    }
    bool checkv4(string s)
    {
        s.push_back('.');
        int k=0;
        for(size_t i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                if(i==k)
                    return false;
                string str=s.substr(k,i-k);
                if(isvalidv4(str)==false)
                    return false;
                k=i+1;
            }
        }
        return true;
    }
    bool isvalidv6(char ch)
    {
        if(ch>='0'&&ch<='9'||ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')
            return true;
        else
            return false;
    }
    bool checkv6(string s)
    {
        int ch_num=0;
        s.push_back(':');
        for(size_t i=0;i<s.size();i++)
        {
            if(s[i]==':')
            {
                if(ch_num>4||ch_num==0)
                    return false;
                ch_num=0;
            }
            else if(!isvalidv6(s[i]))
            {
                return false;
            }
            else
            {
                ch_num++;
            }
        }
        return true;
    }
    string solve(string IP)
    {
        // write code here
        if(type(IP))
        {
            if(checkv4(IP)==false)
                return "Neither";
            return "IPv4";
        }
        else
        {
            if(checkv6(IP)==false)
                return "Neither";
            return "IPv6";
        }
    }
};