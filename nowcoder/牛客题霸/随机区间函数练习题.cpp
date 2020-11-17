class RandomSeg {
public:
    // 等概率返回[0,1)
	double f() {
	    return rand() * 1.0 / RAND_MAX;
	}
	// 通过调用f()来实现
    double random(int k, double x) {
        double max=0;
        double rand=0;
        for(int i=0;i<k;i++)
        {
            rand=f();
            max=max>rand?max:rand;
        }
        return max;
    }
};