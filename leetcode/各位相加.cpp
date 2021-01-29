class Solution {
public:
    int addDigits(int num) {
        string s=to_string(num);
        num=0;
        for(int i=0;i<s.size();i++)
        {
            num+=s[i]-'0';
        }
        if(num>=0&&num<=9)
            return num;
        else
        {
            return addDigits(num);
        }
    }
};