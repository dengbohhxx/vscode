class Solution {
public:
    int getnext(int n)
    {
         string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.size();i++)
        {
                sum+=(s[i]-'0')*(s[i]-'0');
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=getnext(n);
        while(fast!=1&&fast!=slow)
        {
            slow=getnext(slow);
            fast=getnext(getnext(fast));
        }
        return fast==1;
    }
};