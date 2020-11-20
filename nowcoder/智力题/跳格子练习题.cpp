class Jump {
public:
    int checkWin(int n) {
        // write code here
         if((n-1)% 4== 0)
            return 0;
        else
            return 1;
    }
};