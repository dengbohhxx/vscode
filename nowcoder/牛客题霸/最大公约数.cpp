class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求出a、b的最大公约数。
     * @param a int 
     * @param b int 
     * @return int
     */
    int gys(int a,int b)
    {
        while(a%b!=0)
        {
            int temp=a;
            a=b;
            b=temp%b;
        }
        return b;
    }
    int gcd(int a, int b) {
        // write code here
        int c=gys(a,b);
        return c;
    }
};