class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        int n=0;
        for(int i=0;i<length;i++)
        {
            if(iniString[i]==' ')
                n++;
        }
        int m=length+2*n-1;
        string s=iniString.append(2*n,'0');
        for(int i=length-1;i>=0;i--)
        {
            if(iniString[i]==' ')
            {
                s[m--]='0';
                s[m--]='2';
                s[m--]='%';
            }
            else
            {
                s[m--]=iniString[i];
            }
            
        }
        return s;
    }
};