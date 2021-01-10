class Solution {
public:
    /**
     * 
     * @param strs string字符串vector 
     * @return string字符串
     */
    string longestprefix(string str1,string str2)
    {
        int len=min(str1.size(),str2.size());
        int index=0;
        while(index<len&&str1[index]==str2[index])
        {
            index++;
        }
        return str1.substr(0,index);
    }
    string longestCommonPrefix(vector<string>& strs) {
        // write code here
        int n=strs.size();
        string prefix;
        if(n==0)
            return prefix;
        prefix=strs[0];
        for(int i=1;i<n;i++)
        {
            prefix=longestprefix(prefix,strs[i]);
            if(prefix.size()==0)
                break;
        }
        return prefix;
    }
};