class Solution {
public:
    int StrToInt(string str) {
        int n=str.size();
        if(n==0)
            return 0;
        if((str[0]<'1'||str[0]>'9')&&((str[0]!='+')&&(str[0]!='-')))
            return 0;
            for(int i=1;i<n;i++)
            {
                if(str[i]<'0'||str[i]>'9')
                    return 0;
            }
            if(str[0]=='+'||str[0]=='-')
            {
                int num=0;
                int base=1;
                for(int i=n-1;i>0;i--)
                {
                    num+=(str[i]-'0')*base;
                    base*=10;
                }
                if(str[0]=='+')
                    return num;
                if(str[0]=='-')
                    return 0-num;
            }

                int num=0;
                int base=1;
                for(int i=n-1;i>=0;i--)
                {
                     num+=(str[i]-'0')*base;
                    base*=10;
                }
                return num;
    }
};