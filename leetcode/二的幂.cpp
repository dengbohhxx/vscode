class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int k=0;
        unsigned int i=1;
        while(i)
        {
            if(i&n)
            {
                k++;
            }
            i=i<<1;
        }
        if(k==1)
            return true;
        return false;
    }
};