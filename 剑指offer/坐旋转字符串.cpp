/*
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int size=str.size();
        if(size==0)
            return str;
        string s=str+str;
        int k=n%size;
        string str1(s.begin()+k,s.begin()+k+size);
        return str1;
    }
};
*/
class Solution {
public:
    void reverse(string&str,int start,int end)
    {
        while(start<end)
        {
            swap(str[start],str[end]);
            start++;
            end--;
        }
    }
    string LeftRotateString(string str, int n) {
        int len=str.size();
        if(len==0||n==0)
            return str;
        if(len<n)
            n%=len;
        reverse(str,0,n-1);
        reverse(str,n,len-1);
        reverse(str,0,len-1);
        return str;
    }
};