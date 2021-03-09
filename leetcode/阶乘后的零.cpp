class Solution {
public:
    int trailingZeroes(int n) {
        if(n<5)
            return 0;
        int res=0;
        int cur=0;
        for(int i=5;i<=n;i++)
        {
            cur=i;
            while(cur%5==0)
            {
                res++;
                cur=cur/5;
            }
        }
        return res;
    }
};