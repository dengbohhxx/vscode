class Ants {
public:
    int gcd(int x,int y)
    {
        if(x%y==0)
            return y;
        else
            return gcd(y,x%y);
    }
    vector<int> collision(int n) {
        // write code here
        int fm=pow(2,n);
        int fz=fm-2;
        vector<int> vec(2);
        int d=gcd(fm,fz);
        if(d!=1)
        {
            vec[0]=fz/d;
            vec[1]=fm/d;
        }
        else
        {
            vec[0]=fz;
            vec[1]=fm;
        }
        return vec;
    }
};