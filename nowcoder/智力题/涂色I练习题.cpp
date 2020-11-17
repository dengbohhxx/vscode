class Paint {
public:
    int getMost(int n, int m) {
        // write code here
        if(m*n%2==0)
            return m*n/2;
        else
            return m*n/2+1;
    }
};