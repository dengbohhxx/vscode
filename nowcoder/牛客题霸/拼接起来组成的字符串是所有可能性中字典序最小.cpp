class Solution {
public:
    /**
     * 
     * @param strs string字符串vector the strings
     * @return string字符串
         string minString(vector<string>& strs) {
        // write code here
        string str;
        if(strs.size()==0)
            return str;
        for(int i=strs.size()-1;i>=1;i--)
        {
            for(int j=0;j<i;j++)
            {
                if(strs[j]+strs[i]>strs[i]+strs[j])
                    swap(strs[i],strs[j]);
            }
        }
        for(int i=0;i<strs.size();i++)
        {
            str+=strs[i];
        }
        return str;
    }
     */
    static bool cmp(string s1,string s2)
    {
        return s1+s2<s2+s1;
    }
    string minString(vector<string>& strs) {
        // write code here
        sort(strs.begin(),strs.end(),cmp);
        string str;
        for(int i=0;i<strs.size();i++)
        {
            str+=strs[i];
        }
        return str;
    }
};