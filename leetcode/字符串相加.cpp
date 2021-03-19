class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.size();
        int len2=num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int newlen=max(len1,len2)+1;
        vector<int> vec(newlen,0);
        for(int i=0;i<newlen;i++)
        {
            int temp1=0;
            int temp2=0;
            if(i<len1)
            {
                temp1=num1[i]-'0';
            }
            if(i<len2)
            {
                temp2=num2[i]-'0';
            }
            vec[i]=temp2+temp1;
        }
        int flag=0;
        for(int i=0;i<newlen;i++)
        {
            int temp=flag+vec[i];
            flag=temp/10;
            vec[i]=temp%10;
        }
        string s;
        reverse(vec.begin(),vec.end());
        int  i=0;
        if(vec[0]==0)
            i=1;
        for(;i<newlen;i++)
        {
            s+=to_string(vec[i]);
        }
        return s;
    }
};