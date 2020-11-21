class Solution {
public:
	void replaceSpace(char *str,int length) {
        int k=0;
        for(int i=0;i<length;i++)
        {
            if(str[i]==' ')
                k++;
        }
        int newidx=length+2*k-1;
        for(int i=length-1;i>=0;i--)
        {
            if(str[i]!=' ')
                str[newidx--]=str[i];
            else
            {
                str[newidx--]='0';
                str[newidx--]='2';
                str[newidx--]='%';
            }
        }
	}
};