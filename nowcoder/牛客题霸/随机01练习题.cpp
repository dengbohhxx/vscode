class RandomP {
public:
	static int f();
};

class Random01 {
public:
    // 用RandomP::f()实现等概率的01返回
    int randp()
    {
        return RandomP::f();
    }
    int random01() {
        int a=randp();
        int b=randp();
        while(a+b!=1)
        {
            a=randp();
            b=randp();
        }
        if(a==1)
            return 1;
        else
            return 0;
    }
};