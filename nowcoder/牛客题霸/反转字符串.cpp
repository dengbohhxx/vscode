/*
class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     
    string solve(string str) {
        // write code here
        reverse(str.begin(),str.end());
        return str;
    }
};
*/
class Solution {
public:
    /**
     * 反转字符串
     * @param str string字符串 
     * @return string字符串
     */
    void reverse(string &str,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            swap(str[i],str[j]);
            i++;
            j--;
        }
    }
    string solve(string str) {
        // write code here
        reverse(str,0,str.size()-1);
        return str;
    }
};