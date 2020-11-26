class Solution {
public:
    void reverse(string &s,int start,int end)
    {
        int i=start;
        int j=end;
        while(i<j)
        {
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
    string ReverseSentence(string str) {
        int size=str.size();
        if(size==0)
            return str;
        reverse(str,0,size-1);
        int str_start=0;
        str+=' ';
        for(int i=0;i<str.size();i++)
        {
            if(str[i]==' ')
            {
                reverse(str,str_start,i-1);
                str_start=i+1;
            }
        }
        str.pop_back();
        return str;
    }
};