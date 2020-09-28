class Translation {
public:
    string stringTranslation(string A, int n, int len) {
        // write code here
        reverse(A.begin(),A.begin()+len);
        reverse(A.begin()+len,A.end());
        reverse(A.begin(),A.end());
        return A;
    }
};
class Translation {
public:
    void reverse(string &s,int first,int last)
    {
        int f=first;
        int l=last;
        while(f<l)
        {
            swap(s[f],s[l]);
            f++;
            l--;
        }
    }
    string stringTranslation(string A, int n, int len) {
        // write code here
        reverse(A,0,len-1);
        reverse(A,len,n-1);
        reverse(A,0,n-1);
        return A;
    }
};