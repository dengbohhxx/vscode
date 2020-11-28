class Solution {
public:
    bool mat(char* str, char* pattern)
    {
        if(*str=='\0'&&*pattern=='\0')//str、pattern都为空，返回true
            return true;
        if(*str!='\0'&&*pattern=='\0')//str不为空，pattern为空，匹配失败
            return false;
        if(*(pattern+1)=='*')//pattern的下一个字符为‘*’
        {
            if(*str==*pattern||*pattern=='.'&&*str!='\0')
                return mat(str+1,pattern)||mat(str,pattern+2);//X*匹配多个字符，继续匹配s1下个字符||匹配0个字符
            else
                return mat(str,pattern+2); 
        }
        else//pattern的下一个字符不为‘*’
        {
            if(*str==*pattern||*pattern=='.'&&*str!='\0')
            {
                return mat(str+1,pattern+1);//判断str和pattern的下一位是否match
            }
            else
                return false;
        }
    }
    bool match(char* str, char* pattern)
    {
        if(str==NULL||pattern==NULL)
            return false;
        return mat(str,pattern);
    }
};