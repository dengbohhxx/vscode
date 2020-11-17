class Championship {
public:
    int gcd(int m,int n)//最大公约数
    {
        if(m%n==0)
            return n;
        else
            return gcd(n,m%n);
    }
    int C(int x,int y)//组合
    {
        int temp=1;
        for(int i=x;i>=x-y+1;i--)
            temp*=i;
        for(int i=1;i<=y;i++)
            temp/=i;
        return temp;
    }
    int A(int x,int y)//排列
    {
        int temp=1;
        for(int i=x-y+1;i<=x;i++)
            temp*=i;
        return temp;
    }
        
    vector<int> calc(int k) {
        // write code here
        vector<int> vec(2);
        //if(k==1)
            //return vec;
        int fm=1;
        for(int i=2*k-1;i>=1;)//分母
        {
            fm=fm*i;
            i=i-2;
        }
        int fz=C(k+1,k-1)*A(k-1,k-1);//分子
        int d=gcd(fz,fm);
        fz=fm-fz;
        if(d==1)
        {
            vec[0]=fz;
            vec[1]=fm;
        }
        else
        {
            vec[0]=fz/d;
            vec[1]=fm/d;
        }
        return vec;
    }
};