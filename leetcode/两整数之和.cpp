class Solution {
public:
    int getSum(int a, int b) {
        while(b){
        //求进位值，两数相与，需要进位的地方为1，不需要进位的地方为0，再左移动一位即可
        int c = (unsigned int)(a & b) << 1;
        //两数异或将值放入其中一个种
        a = a ^ b;
        //另一个值用进位值替换
        b = c;
    }
    return a;
    }
};