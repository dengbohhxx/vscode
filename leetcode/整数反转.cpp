#include<algorithm>
class Solution {
public:
    int reverse(int x) {
        int flag=1;
        if(x==0)
            return 0;
        if(x<0)
            flag=-1;
        x=abs(x);
        string str=to_string(x);
        ::reverse(str.begin(),str.end());
        long long res=0;
        for(int i=0;i<str.size();i++)
        {
            res=res*10+str[i]-'0';
        }
        res=res*flag;
        if(res>INT_MAX||res<INT_MIN)
        {
                return 0;
        }
        return res;
    }
};