class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
            int n=strs.size();
            string str;
            if(n==0)
                return str;
            int len=strs[0].size();
            for(int i=0;i<len;i++)
            {
                char c=strs[0][i];
                for(int j=1;j<n;j++)
                {
                    if(i==strs[j].size()||strs[j][i]!=c)
                            return str;
                }
                str+=c;
            }
            return str;
    }
};