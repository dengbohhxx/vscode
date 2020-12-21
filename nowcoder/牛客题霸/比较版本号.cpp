class Solution {
public:
    /**
     * 比较版本号
     * @param version1 string字符串 
     * @param version2 string字符串 
     * @return int整型
     */
    int compare(string version1, string version2) {
        // write code here
        int i1=0;
        
        int j1=0;
        
        int res=0;
        while(i1<version1.size()||j1<version2.size())
        {
            int i2=i1;
            int j2=j1;
            while(version1[i2]!='.'&&i2<version1.size())
            {
                i2++;
            }
            while(version2[j2]!='.'&&j2<version2.size())
            {
                j2++;
            }
            int str1=(i1==i2)?0:stoi(version1.substr(i1,i2-i1));
            int str2=(j1==j2)?0:stoi(version2.substr(j1,j2-j1));
            if(str1<str2)
            {
                res=-1;
                break;
            }
            else if(str1>str2)
            {
                res=1;
                break;
            }
            else
            {
                res=0;
            }
            i1=i2+1;
            j1=j2+1;
        }
        return res;
    }
};