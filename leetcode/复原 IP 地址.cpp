#include<string>
class Solution {
public:
    bool isvalid(string &str)
    {
        if((str.size()>1&&str[0]=='0')||str.size()>3)
            return false;
        return stoi(str)<256?true:false;
    }
    void dfs(string s,vector<string> &res,vector<string> &cur,int pos)
    {
        if(cur.size()==4&&pos==s.size())
        {
            res.push_back(cur[0]+'.'+cur[1]+'.'+cur[2]+'.'+cur[3]);
            return;
        }
        for(int i=pos;i<s.size();i++)
        {
            string temp=s.substr(pos,i-pos+1);
            if(isvalid(temp))
            {
                cur.push_back(temp);
                dfs(s,res,cur,i+1);
                cur.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> arrres,arrtemp;
        int n=s.size();
        if(n==0||n>12)
            return arrres;
        dfs(s,arrres,arrtemp,0);
        return arrres;
    }
};