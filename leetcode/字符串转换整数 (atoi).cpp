class Solution {
public:
    int myAtoi(string s) {
        int n=s.size();
        if(n==0)
            return 0;
        int i=0;
        while(s[i]==' ')
        {
            i++;
        }
        int sign=1;
        if(s[i]=='+'||s[i]=='-')
        {
            sign=(s[i]=='+')?1:-1;
            i++;
        }
        long long res=0;
        while(s[i]>='0'&&s[i]<='9')
        {
            res=res*10+s[i]-'0';
            i++;
            if(res*sign>=INT_MAX)
            {
                return INT_MAX;
            }
            if(res*sign<=INT_MIN)
            {
                return INT_MIN;
            }
        }
        return (int)(sign*res);

    }
};