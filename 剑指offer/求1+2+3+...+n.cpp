/*
if (n==1) return 1;
也就是说如果n==1,需要终止递归，所以我们想到了逻辑与&&连接符。
A&&B，表示如果A成立则执行B，否则如果A不成立，不用执行B
因此我们可以这样。在n>1的时候，执行递归函数。*/
class Solution {
public:
    int Sum_Solution(int n) 
    {
        n>1&&(n+=Sum_Solution(n-1));
        return n;
    }
};