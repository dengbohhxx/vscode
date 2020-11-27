class Solution {
public:
    bool MATCH(char* str, char* pattern)
    {
        if(*str=='\0'&&*pattern=='\0')
            return true;
        if(*(pattern+1)=='*')
        {
            if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
               return MATCH(str+1,pattern)||MATCH(str,pattern+2);
            else
               return MATCH(str,pattern+2);
        }
        else if(*str==*pattern||(*pattern=='.'&&*str!='\0'))
           return MATCH(str+1,pattern+1);

        return false;
    }
    
    
    bool match(char* str, char* pattern)
    {
    if(str==NULL||pattern==NULL)
        return false;
    return MATCH(str,pattern);
    }
};