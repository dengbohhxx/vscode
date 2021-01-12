class Solution {
public:
    string prefix(string s1,string s2)
    {
        int len=min(s1.size(),s2.size());
        int index=0;
        while(index<len&&s1[index]==s2[index])
        {
            index++;
        }
        return s1.substr(0,index);
    }
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string pfix;
        if(n==0)
            return pfix;
        pfix=strs[0];
        for(int i=1;i<n;i++)
        {
            pfix=prefix(pfix,strs[i]);
        }
        return pfix;
    }
};