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
/*
class QuickPower {
public:
    int getPower(int k, int N) {
        // write code here
        if(N == 0)
            return 1;
        if(N == 1)
            return k;
         
        if(N % 2 == 1)
        {
            long long res = getPower(k,N/2)% 1000000007;
            //return (res * res * k) > INT_MAX ? (res * res * k) % 1000000007 : (res * res * k);
            return res % 1000000007* res% 1000000007 * k % 1000000007;    
        }
        else
        {
            long long res = getPower(k,N/2)% 1000000007 ;
            //return (res * res) > INT_MAX ? (res * res) % 1000000007 : (res * res);
            return res% 1000000007 * res % 1000000007;
        }
    }
};
*/