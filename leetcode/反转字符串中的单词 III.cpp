class Solution {
public:
    void reverse(string &s)
    {
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            swap(s[start],s[end]);
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        vector<string> vec;
        s+=' ';
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                string str=s.substr(k,i-k);
                vec.push_back(str);
                k=i+1;
            }
        }
        string s1;
        for(int i=0;i<vec.size();i++)
        {
            reverse(vec[i]);
            s1+=vec[i];
            s1+=' ';
        }
        s1.pop_back();
        return s1;
    }
};