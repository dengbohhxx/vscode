class Solution {
public:
    double Power(double base, int exponent) {
        if(base==0)
            return 0;
        if(exponent==0)
            return 1;
        else if(exponent<0)
            return 1/Power(base, -exponent);
        else
        {
            if(exponent%2==0)
                return Power(base, exponent>>1)*Power(base, exponent>>1);
            else
                return Power(base, exponent>>1)*Power(base, exponent>>1)*base;
        }
            
    }
};