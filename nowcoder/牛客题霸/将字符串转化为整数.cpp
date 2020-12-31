class Solution {
public:
    int atoi(const char *str) {
         if(*str=='\0')//空串
            return 0;
        const char * p=str;
        while(*p==' ')//处理前面的空格
        {
            p++;
        }
        int sign=1;
        if(*p=='+'||*p=='-')//处理正负号
        {
            sign=(*p=='+')?1:-1;
            p++;
        }
        long res=0;
        while(*p>='0'&&*p<='9')//一旦有非数字元素，只处理之前的数字
        {
            res=res*10+*p-'0';
            p++;
            if(res*sign>=INT_MAX)//数字越界
                return INT_MAX;
            if(res*sign<=INT_MIN)//数字越界
                return INT_MIN;
        }
        return (int)(res*sign);
    }
};