class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n==0||numRows==1)
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int cur=0;
        bool goingdown=false;
        for(int i=0;i<s.size();i++)
        {
            rows[cur]+=s[i];
            if(cur==0||cur==numRows-1)
            {
                goingdown=!goingdown;
            }
            cur+=goingdown?1:-1;
        }
        string res;
        for(int i=0;i<rows.size();i++)
        {
            res+=rows[i];
        }
        return res;
    }
};