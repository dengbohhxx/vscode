class Solution {
public:
    double mypow(double x,int n)
    {
        if(n==0)
            return 1.0;
        double temp=mypow(x,n/2);
        return n%2==0?temp*temp:temp*temp*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(n>=0)
            return mypow(x,N);
        else
            return 1.0/mypow(x,-N);
    }
};