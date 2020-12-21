class Transform {
public:
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
    void tran(char &c)
    {
        if(c>='a'&&c<='z')
        {
            c='A'+(c-'a');
        }
        else if(c>='A'&&c<='Z')
        {
            c='a'+(c-'A');
        }
        else
        {
            c=c;
        }
    }
    string trans(string s, int n) {
        // write code here
        if(n==0||n==1)
            return s;
        s+=' ';
        int j=0;
        for(int i=0;i<=n;i++)
        {
            if(s[i]==' ')
            {
                reverse(s,j,i-1);
                j=i+1;
            }
        }
        s.pop_back();
        reverse(s,0,n-1);
        for(int i=0;i<n;i++)
        {
            tran(s[i]);
        }
        return s;
    }
};