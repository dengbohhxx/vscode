class QuickPower {
public:
    int getPower(int k, int N) {
        // write code here
        if(N==0)
            return 1;
        long temp=k;
        long res=1;
        for(int i=N;i>0;i>>=1)
        {
            if((i&1)!=0)
            {
                res*=temp;
            }
            temp=temp*temp%1000000007;
            res%=1000000007;
        }
        return (int)res;
    }
};