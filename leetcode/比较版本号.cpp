class Solution {
public:
    vector<int> strtovec(string ver)
    {
        ver+=".";
        int n=ver.size();
        vector<int> vec;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(ver[i]=='.')
            {
                string str=ver.substr(k,i-k);
                int temp=0;
                for(int i=0;i<str.size();i++)
                {
                    temp=temp*10+(str[i]-'0');
                }
                vec.push_back(temp);
                k=i+1;
            }
        }
        return vec;
    }
    int compareVersion(string version1, string version2) {
        vector<int> vec1=strtovec(version1);
        vector<int> vec2=strtovec(version2);
        int m=vec1.size();
        int n=vec2.size();
        int len=max(m,n);
        int res=0;
        for(int i=0;i<len;i++)
        {
            int temp1=0;
            int temp2=0;
            if(i<m)
            {
                temp1=vec1[i];
            }
            if(i<n)
            {
                temp2=vec2[i];
            }
            if(temp1>temp2)
            {
                res=1;
                break;
            }
            else if(temp1<temp2)
            {
                res=-1;
                break;
            }
            else
            {
                continue;
            }
        }
        return res;

    }
};