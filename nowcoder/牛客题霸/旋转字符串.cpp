class Solution {
public:
    /**
     * 旋转字符串
     * @param A string字符串 
     * @param B string字符串 
     * @return bool布尔型
     */
    bool solve(string A, string B) {
        // write code here
        int len1=A.size();
        int len2=B.size();
        if(len1!=len2)
            return false;
        string str=A+A;
        if(str.find(B)!=string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};