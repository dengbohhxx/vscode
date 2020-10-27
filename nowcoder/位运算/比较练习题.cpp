class Compare {
public:
    int f(int x)
    {
        return x^1;
    }
    int find(int x)
    {
        return (x>>31)&1;
    }
    int getMax(int a, int b) {
        // write code here
        int c=a-b;
        int temp1=find(c);
        int temp2=f(temp1);
        return a*temp2+b*temp1;
    }
};