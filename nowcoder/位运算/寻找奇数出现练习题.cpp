class OddAppearance {
public:
    int findOdd(vector<int> A, int n) {
        // write code here
        int a=0;
        for(vector<int>::iterator iter=A.begin();iter!=A.end();iter++)
            a^=*iter;
        return a;
    }
};