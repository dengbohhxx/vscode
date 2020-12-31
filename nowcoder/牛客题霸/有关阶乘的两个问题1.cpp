class Solution {
public:
    /**
     * the number of 0
     * @param n long长整型 the number
     * @return long长整型
     long long thenumberof0(long long n) {
        // write code here
       if(n<5)
           return 0;
        long long res=0;
        long long cur=0;
        for(long long i=5;i<=n;i++)
        {
            cur=i;
            while(cur%5==0)
            {
                res++;
                cur=cur/5;
            }
        }
        return res;
    }
     *///最终落脚点还是求5的个数
    long long thenumberof0(long long n) {
        // write code here
        long long count=0;
        while(n>0)
        {
            count+=n/5;
            n=n/5;
        }
        return count;
    }
};